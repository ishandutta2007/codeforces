#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
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
typedef vector<db> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

VPi v[500005];
int R;
bool chk[500005];
int col[500005];
int bfs(int N){
	queue<int> q;
	MEM0(chk);
	chk[N]=1;
	q.push(N);
	int last=N;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		last=x;
		for(auto P:v[x]){
			if(!chk[P.X]){
				q.push(P.X);
				chk[P.X]=1;
			}
		}
	}
	return last;
}
int idx[500005];
int S[500005],E[500005],depth[500005],cc;

int tree[1048576][2],rev[500005],col2[500005];
bool lazy[1048576];
void init(int node, int S, int E)
{
	lazy[node]=0;
	if (S == E)
	{
		int i=rev[S];
		if(col2[i]==0)tree[node][0]=depth[i],tree[node][1]=0;
		else tree[node][1]=depth[i],tree[node][0]=0;
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	for(int i:{0,1})tree[node][i]=max(tree[node*2][i],tree[node*2+1][i]);
}
void propagation(int node, int S, int E)
{
	if (lazy[node])
	{
		swap(tree[node][0],tree[node][1]);
		if (S != E)
		{
			lazy[2 * node] ^= 1;
			lazy[2 * node + 1] ^= 1;
		}
		lazy[node] = 0;
	}
}
void upd(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		lazy[node] ^= 1;
		propagation(node, S, E);
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j);
	for(int i:{0,1})tree[node][i]=max(tree[node*2][i],tree[node*2+1][i]);
}
int find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return 0;
	if (j >= E && i <= S) return tree[node][0];
	return max(find(node * 2, S, (S + E) / 2, i, j), find(2 * node + 1, (S + E) / 2 + 1, E, i, j));
}

void dfs(int N,int color,int p=-1,int d=0){
	S[N]=++cc;
	rev[cc]=N;
	col2[N]=color;
	depth[N]=d;
	for(auto [next,i]:v[N]){
		if(next==p)continue;
		idx[i]=next;
		dfs(next,color^col[i],N,d+1);
	}
	E[N]=cc;
}
int ans[500005],Q[500005];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,1,n-1,1){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].pb(mp(y,i));
		v[y].pb(mp(x,i));
		col[i]=z;
	}
	R=bfs(1);
	R=bfs(R);
	dfs(R,0);
	init(1,1,n);
	int q;
	scanf("%d",&q);
	fup(i,0,q-1,1){
		scanf("%d",Q+i);
		upd(1,1,n,S[idx[Q[i]]],E[idx[Q[i]]]);
		ans[i]=find(1,1,n,1,n);
	}
	cc=0;
	R=bfs(R);
	dfs(R,0);
	init(1,1,n);
	fup(i,0,q-1,1){
		upd(1,1,n,S[idx[Q[i]]],E[idx[Q[i]]]);
		ans[i]=max(ans[i],find(1,1,n,1,n));
		printf("%d\n",ans[i]);
	}
}