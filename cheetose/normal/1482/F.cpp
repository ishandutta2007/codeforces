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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[200000];
Vi v[200001];
struct Node {
	int lsum, rsum, maxsum, sum;
};
Node tree[524288];
void init(int node,int S,int E,int k){
	if(S==E){
		tree[node].lsum = k;
		tree[node].rsum = k;
		tree[node].maxsum = k;
		tree[node].sum = k;
		return;
	}
	init(node<<1,S,(S+E)/2,k);
	init(node<<1|1,(S+E)/2+1,E,k);
	tree[node].lsum = max(tree[node * 2].lsum, tree[node * 2].sum + tree[node * 2 + 1].lsum);
	tree[node].rsum = max(tree[node * 2 + 1].rsum, tree[node * 2 + 1].sum + tree[node * 2].rsum);
	tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
	tree[node].maxsum = max({ tree[node * 2].maxsum, tree[node * 2 + 1].maxsum, tree[node * 2].rsum + tree[node * 2 + 1].lsum });
}
void upd(int node, int S, int E, int i, int k)
{
	if (S == E)
	{
		tree[node].lsum = k;
		tree[node].rsum = k;
		tree[node].maxsum = k;
		tree[node].sum = k;
		return;
	}
	if (i <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, i, k);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, i, k);
	tree[node].lsum = max(tree[node * 2].lsum, tree[node * 2].sum + tree[node * 2 + 1].lsum);
	tree[node].rsum = max(tree[node * 2 + 1].rsum, tree[node * 2 + 1].sum + tree[node * 2].rsum);
	tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
	tree[node].maxsum = max({ tree[node * 2].maxsum, tree[node * 2 + 1].maxsum, tree[node * 2].rsum + tree[node * 2 + 1].lsum });
}
int ans[200000];
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1){
		scanf("%d",a+i);
		v[a[i]].pb(i);
	}
	init(1,0,n-1,1);
	fup(x,1,n,1){
		for(int y:v[x]){
			upd(1,0,n-1,y,INF);
			int t=tree[1].maxsum-INF;
			ans[y]=max(ans[y],(t+1)/2);
			upd(1,0,n-1,y,1);
		}
		for(int y:v[x])upd(1,0,n-1,y,-1);
	}
	init(1,0,n-1,1);
	fdn(x,n,1,1){
		for(int y:v[x]){
			upd(1,0,n-1,y,INF);
			int t=tree[1].maxsum-INF;
			ans[y]=max(ans[y],t/2);
			upd(1,0,n-1,y,1);
		}
		for(int y:v[x])upd(1,0,n-1,y,-1);
	}
	fup(i,0,n-1,1)printf("%d ",ans[i]);
}