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
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

struct node {
	int child[26];
	node()
	{
		MEM_1(child);
	}
};
bool valid[1000001];
int d[1000001],query[1000001];
vector<node> trie;
int init()
{
	node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}

int tree[2097152], lazy[2097152];
void INIT(int node,int S,int E){
	tree[node]=INF;
	if(S==E)return;
	INIT(node*2,S,(S+E)/2);
	INIT(node*2+1,(S+E)/2+1,E);
}
void propagation(int node, int S, int E)
{
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if (S != E)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void upd(int node, int S, int E, int i, int j, int val)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		lazy[node]+=val;
		propagation(node,S,E);
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j, val);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, val);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
void upd2(int node, int S, int E, int k, int val)
{
	propagation(node, S, E);
	if(S==E){
		tree[node]=val;
		return;
	}
	if(k<=(S+E)/2)upd2(2 * node, S, (S + E) / 2, k, val);
	else upd2(2 * node + 1, (S + E) / 2 + 1, E, k, val);
	tree[node] = min(tree[2 * node]+lazy[2*node], tree[2 * node + 1]+lazy[2*node+1]);
}
int find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return INF;
	if (j >= E && i <= S) return tree[node];
	return min(find(node * 2, S, (S + E) / 2, i, j), find(2 * node + 1, (S + E) / 2 + 1, E, i, j));
}
int n;
void dfs(int N,int depth,int val){
	d[N]=val+1;
	if(valid[N])d[N]=min(d[N],find(1,0,n,0,depth-1));
	upd2(1,0,n,depth,d[N]+1);
	if(valid[N])upd(1,0,n,0,depth,1);
	fup(i,0,25,1){
		if(trie[N].child[i]!=-1)dfs(trie[N].child[i],depth+1,d[N]);
	}
	upd2(1,0,n,depth,INF);
}
int main(){
	init();
	scanf("%d",&n);
	INIT(1,0,n);
	fup(i,1,n,1){
		int p;
		char c;
		scanf("%d %c",&p,&c);
		init();
		trie[p].child[c-'a']=i;
	}
	int q;
	scanf("%d",&q);
	fup(i,1,q,1){
		int x;
		scanf("%d",&x);
		query[i]=x;
		valid[x]=1;
	}
	dfs(0,0,-1);
	fup(i,1,q,1)printf("%d ",d[query[i]]);
}