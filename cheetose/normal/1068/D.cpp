#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 987654321
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int d[100002][201][2];
int a[100002],sum[100002][201][2];
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 1, n, 1)scanf("%d", a + i);
	fup(j, 1, 200, 1)
	{
		if (a[1] == -1)d[1][j][0] = 1;
		else d[1][j][0] = (a[1] == j);
		sum[1][j][0] = (sum[1][j - 1][0] + d[1][j][0]) % MOD;
	}
	fup(i, 2, n, 1)
	{
		fup(j, 1, 200, 1)
		{
			if (a[i] != -1)
			{
				if (a[i] == j)
				{
					d[i][j][0] = (sum[i - 1][j - 1][0] + sum[i - 1][j - 1][1]) % MOD;
					d[i][j][1] = (sum[i - 1][200][1] - sum[i - 1][j - 1][1] + MOD) % MOD;
					d[i][j][1] = (d[i][j][1] + d[i - 1][j][0]) % MOD;
				}
				else d[i][j][0] = d[i][j][1] = 0;
			}
			else
			{
				d[i][j][0] = (sum[i - 1][j - 1][0] + sum[i - 1][j - 1][1]) % MOD;
				d[i][j][1] = (sum[i - 1][200][1] - sum[i - 1][j - 1][1] + MOD) % MOD;
				d[i][j][1] = (d[i][j][1] + d[i - 1][j][0]) % MOD;
			}
			sum[i][j][0] = (sum[i][j - 1][0] + d[i][j][0]) % MOD;
			sum[i][j][1] = (sum[i][j - 1][1] + d[i][j][1]) % MOD;
		}
	}
	printf("%d", sum[n][200][1]);
}