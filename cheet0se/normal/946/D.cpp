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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
int MOD = 1000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };//
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int a[500][500];
int d[500][501];
Vi v[500];
Vi vv[500];
int n, m, k;
void ini(int i)
{
	fup(j, 0, m - 1, 1)
		if (a[i][j] == 1)v[i].push_back(j);
}
void go(int i)
{
	vv[i].push_back(0);
	if (v[i].empty())return;
	int N = v[i].size();
	int t = v[i].back() - v[i][0] + 1;
	fdn(k, N-2, 0, 1)
	{
		int temp = INF;
		for (int j = 0; k + j < N; j++)
		{
			temp = min(temp, v[i][k + j] - v[i][j] + 1);
		}
		vv[i].push_back(t - temp);
	}
	vv[i].push_back(t);
}
int go(int N, int K)
{
	if (N == n)return 0;
	int &ret = d[N][K];
	if (ret != -1)return ret;
	ret = 0;
	int tt = min((int)vv[N].size()-1, K);
	fup(i, 0, tt, 1)
	{
		ret = max(ret, vv[N][i] + go(N + 1, K - i));
	}
	return ret;
}
int main()
{
	MEM_1(d);
	scanf("%d%d%d", &n, &m, &k);
	fup(i, 0, n - 1, 1)fup(j, 0, m - 1, 1)scanf("%1d", &a[i][j]);
	int ans = 0;
	fup(i, 0, n - 1, 1)
	{
		ini(i);
		go(i);
		if (v[i].empty())continue;
		ans += v[i].back() - v[i][0] + 1;
	}
	printf("%d", ans - go(0, k));
}