#include<cstdio>
#include<cstdlib>
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
int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM){ll ret = 1;for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if(a==0||b==0)return a+b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[2002];
int one[2002], two[2002];
int d[2002][2002][2];
int go(int L, int R,int c)
{
	if (L > R)return 0;
	int &ret = d[L][R][c];
	if (ret != -1)return ret;
	ret = go(L+1,R,c);
	if (a[L] == 1)
	{
		ret = max(ret, 1 + go(L + 1, R, 0));
	}
	else
	{
		if (c == 1)ret = max(ret, 1 + go(L + 1, R, 1));
	}
	return ret;
}
int main()
{
	MEM_1(d);
	int n;
	scanf("%d", &n);
	fup(i, 1, n, 1)scanf("%d", a + i);
	fup(i, 1, n, 1)
	{
		one[i] = one[i - 1];
		if (a[i] == 1)one[i]++;
	}
	fdn(i, n, 1, 1)
	{
		two[i] = two[i + 1];
		if (a[i] == 2)two[i]++;
	}
	int ans = max(one[n], two[1]);
	fup(i,1,n,1)
		fup(j, i, n, 1)
	{
		ans = max(ans, one[i - 1] + two[j + 1] + go(i, j, 1));
	}
	printf("%d", ans);
}