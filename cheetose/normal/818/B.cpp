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
int MOD = 10001;
ll POW(ll a, ll b){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MOD)if (b & 1)ret = (ret*a) % MOD; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };
int DX[] = { 2,2,1,1,-1,-1,-2,-2 }, DY[] = { 1,-1,2,-2,2,-2,1,-1 };

int a[101];
int b[101];
bool chk[101];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	fup(i, 1, m, 1)scanf("%d", a + i);
	fup(i, 1, m - 1, 1)
	{
		int t = (a[i + 1] - a[i] + n) % n;
		if (t == 0)t = n;
		if (b[a[i]] != 0 && b[a[i]] != t)return puts("-1");
		if (b[a[i]]!=t && chk[t])return puts("-1");
		chk[t] = 1;
		b[a[i]] = t;
	}
	fup(i, 1, n, 1)
	{
		if(b[i]!=0) printf("%d ", b[i]);
		else
		{
			fup(j,1,n,1)
				if (!chk[j])
				{
					chk[j] = 1;
					printf("%d ", j);
					break;
				}
		}
	}
}