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
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<db, db> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

struct Edge {
	int to, r;
	Edge* ori;
	Edge* rev;
	Edge(int T, int R)
	{
		to = T, r = R;
	}
};
vector<Edge *> v[3003];
void addedge(int f, int t, int r)
{
	Edge* ori = new Edge(t, r);
	Edge* rev = new Edge(f, 0);
	ori->rev = rev;
	rev->rev = ori;
	v[f].push_back(ori);
	v[t].push_back(rev);
}
const int S = 0, T = 3001;
int level[3003],work[3003];
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
int a[3001],b[3001];
int main() {
	int n;
	scanf("%d", &n);
	fup(i,1,n,1)scanf("%d",a+i);
	int ans=0;
	fup(i,1,n,1){
		scanf("%d",b+i);
		if(b[i]>0){
			ans+=b[i];
			addedge(S,i,b[i]);
		}
		if(b[i]<0)addedge(i,T,-b[i]);
	}
	fup(i,1,n,1){
		Vi vv;
		fdn(j,i-1,1,1){
			if(a[i]%a[j]==0){
				bool ok=1;
				for(int x:vv)if(x%a[j]==0)ok=0;
				if(ok){
					addedge(i,j,INF);
					vv.pb(a[j]);
				}
			}
		}
	}
	while (bfs())
	{
		MEM0(work);
		while (1)
		{
			int f = dfs(S, T, INF);
			if (f == 0)break;
			ans-=f;
		}
	}
	printf("%d\n",ans);
}