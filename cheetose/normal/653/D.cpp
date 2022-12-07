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
#define INF 987654321987654321
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
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m;
ll c;
iii edge[500];
struct Edge {
	ll to, r, c;
	Edge* ori;
	Edge* rev;
	Edge(ll T, ll R, ll C)
	{
		to = T, r = R, c = C;
	}
};
vector<Edge *> v[51];
void addedge(ll f, ll t, ll r, ll c)
{
	Edge* ori = new Edge(t, r, c);
	Edge* rev = new Edge(f, 0, -c);
	ori->rev = rev;
	rev->rev = ori;
	v[f].push_back(ori);
	v[t].push_back(rev);
}
int S = 0, T;
int level[51],work[51];
bool bfs() {
	MEM_1(level);
	level[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto& nn : v[x]) {
			int next = nn->to;
			if (level[next] == -1 && nn->r > 0) {
				level[next] = level[x] + 1;
				q.push(next);
			}
		}
	}
	return level[T] != -1;
}
ll dfs(int N, int des, ll flow) {
	if (N == des) return flow;

	for (int &i = work[N]; i<v[N].size(); i++) {
		int next = v[N][i]->to;
		if (level[next] == level[N] + 1 && v[N][i]->r > 0) {
			ll df = dfs(next, des, min(v[N][i]->r, flow));
			if (df > 0) {
				v[N][i]->r -= df;
				v[N][i]->rev->r += df;
				return df;
			}
		}
	}
	return 0;
}
bool ok(double k)
{
	fup(i,0,n,1)v[i].clear();
	addedge(S,1,c,0);
	fup(i,0,m-1,1)
	{
		int x,y,z;
		tie(x,y,z)=edge[i];
		ll t=(ll)(1.0*z/k);
		addedge(x,y,t,0);
	}
	ll ans = 0;
	while (bfs())
	{
		MEM0(work);
		while (1)
		{
			ll f = dfs(S, T, INF);
			if (f == 0)break;
			ans += f;
		}
	}
	return ans==c;
}
int main() {
	scanf("%d%d%lld",&n,&m,&c);
	T=n;
	fup(i,0,m-1,1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		edge[i]=iii(x,y,z);
	}
	int TT=100;
	double l=0,r=1000000;
	while(TT--)
	{
		double k=(l+r)/2;
		if(ok(k))l=k;
		else r=k;
	}
	printf("%.10f",r*c);
}