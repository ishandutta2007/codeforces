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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Vi v[200000];
int tot[200000];
int N[200000];
map<int, VPi> M;
int main() {
	int k;
	scanf("%d", &k);
	fup(i, 0, k - 1, 1)
	{
		scanf("%d", N + i);
		fup(ii, 1, N[i], 1)
		{
			int x;
			scanf("%d", &x);
			tot[i] += x;
			v[i].push_back(x);
		}
	}
	fup(i, 0, k - 1, 1)
	{
		int T = tot[i];
		fup(j, 0, N[i] - 1, 1)
		{
			M[T - v[i][j]].push_back(mp(i + 1, j + 1));
		}
	}
	for (auto it = M.begin(); it != M.end(); it++)
	{
		if (it->Y.size() >= 2)
		{
			int nn = it->Y.size();
			bool ok = 0;
			fup(i, 1, nn - 1, 1)
				if (it->Y[i].X != it->Y[0].X)ok = 1;
			if (ok)
			{
				puts("YES");
				printf("%d %d\n", it->Y[0].X, it->Y[0].Y);
				fup(i, 1, nn - 1, 1)
					if (it->Y[i].X != it->Y[0].X)
						return !printf("%d %d\n", it->Y[i].X, it->Y[i].Y);
			}
		}
	}
	puts("NO");
}