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
#define INF 98765
#define PI 3.141592653589793238462643383279502884
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
typedef tuple<int, int, int, int> iiii;
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

int n, m, k, res, deg[200001],ans[200001];
set<int> S[200001];
Pi p[200001];
bool chk[200001];
queue<int> q;
void upd(int x)
{
	if (chk[x] || deg[x] >= k)return;
	q.push(x);
	chk[x] = 1;
	res--;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	res = n;
	fup(i, 1, m, 1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		p[i].X = x, p[i].Y = y;
		S[x].insert(y);
		S[y].insert(x);
		deg[x]++, deg[y]++;
	}
	fup(i, 1, n, 1)upd(i);
	fdn(i, m, 1, 1)
	{
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int y : S[x])
			{
				deg[y]--;
				S[y].erase(x);
				upd(y);
			}
		}
		ans[i] = res;
		int x, y;
		tie(x, y) = p[i];
		if(!chk[x] && !chk[y])
		{
			deg[x]--, deg[y]--;
			upd(x); upd(y);
			S[x].erase(y);
			S[y].erase(x);
		}
	}
	fup(i, 1, m, 1)printf("%d\n", ans[i]);
}