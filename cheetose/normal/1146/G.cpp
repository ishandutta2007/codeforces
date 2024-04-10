#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

struct Edge {
	int to, r;
	Edge* ori;
	Edge* rev;
	Edge(int T, int R)
	{
		to = T, r = R;
	}
};
vector<Edge *> v[2605];
void addedge(int f, int t, int r)
{
	Edge* ori = new Edge(t, r);
	Edge* rev = new Edge(f, 0);
	ori->rev = rev;
	rev->rev = ori;
	v[f].push_back(ori);
	v[t].push_back(rev);
}
const int S = 2603, T = 2604;
int level[2605],work[2605];
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
int dfs(int N, int des, int flow) {
	if (N == des) return flow;

	for (int &i = work[N]; i<v[N].size(); i++) {
		int next = v[N][i]->to;
		if (level[next] == level[N] + 1 && v[N][i]->r > 0) {
			int df = dfs(next, des, min(v[N][i]->r, flow));
			if (df > 0) {
				v[N][i]->r -= df;
				v[N][i]->rev->r += df;
				return df;
			}
		}
	}
	return 0;
}
int main(){
	int n,h,m;
	scanf("%d%d%d",&n,&h,&m);
	int ans=n*h*h;
	fup(i,0,n-1,1)
	{
		addedge(S,i*51,h*h);
		fup(j,1,h,1)
			addedge(51*i+j-1,51*i+j,h*h-j*j);
	}
	fup(i,0,m-1,1)
	{
		int x,y,z,w;
		scanf("%d%d%d%d",&x,&y,&z,&w);
		x--,y--;
		fup(j,x,y,1)addedge(51*j+z,2551+i,INF);
		addedge(2551+i,T,w);
	}
	while (bfs())
	{
		MEM0(work);
		while (1)
		{
			int f = dfs(S, T, INF);
			if (f == 0)break;
			ans -= f;
		}
	}
	printf("%d\n", ans);
}