#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#define mp make_pair
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef vector<iii> Viii;
typedef complex<double> base;
ll MOD = 1000000007;
ll POW(ll a, ll b){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MOD)if (b & 1)ret = (ret*a) % MOD; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[1000],b[1000];
bool chk[1001];
int main()
{
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
		scanf("%d", a + i);
	fup(i, 0, n - 1, 1)
		scanf("%d", b + i);
	Vi v;
	fup(i, 0, n - 1, 1)
		if (a[i] != b[i])v.push_back(i);
	if (v.size() == 1)
	{
		int t = v[0];
		fup(i, 0, n - 1, 1)
		{
			if (i == t)continue;
			chk[a[i]] = 1;
		}
		int tt;
		fup(i, 1, n, 1)
			if (!chk[i])tt = i;
		a[t] = tt;
		fup(i, 0, n - 1, 1)
			printf("%d ", a[i]);
	}
	else
	{
		int t1 = v[0], t2 = v[1];
		fup(i, 0, n - 1, 1)
		{
			if (i == t1 || i == t2)continue;
			chk[a[i]] = 1;
		}
		Vi aa;
		fup(i, 1, n, 1)
		{
			if (!chk[i])aa.push_back(i);
		}
		int tt1 = aa[0], tt2 = aa[1];
		if ((tt1 == a[t1] || tt1 == b[t1]) && (tt2 == a[t2] || tt2 == b[t2])) a[t1] = tt1, a[t2] = tt2;
		else if ((tt1 == a[t2] || tt1 == b[t2]) && (tt2 == a[t1] || tt2 == b[t1])) a[t2] = tt1, a[t1] = tt2;
		fup(i, 0, n - 1, 1)
			printf("%d ", a[i]);
	}
}