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

struct Node {
	ll lmx, lmn, sum;
};
Node tree[262144];
Node merge(Node &L,Node &R){
	Node res;
	res.sum=L.sum+R.sum;
	res.lmx=max(L.lmx,L.sum+R.lmx);
	res.lmn=min(L.lmn,L.sum+R.lmn);
	return res;
}
ll a[100001];
void init(int node,int S,int E){
	if(S==E){
		tree[node]={a[S],a[S],a[S]};
		return;
	}
	int L=node<<1,R=L|1,M=S+E>>1;
	init(L,S,M);init(R,M+1,E);
	tree[node]=merge(tree[L],tree[R]);
}
Node find(int node, int S, int E, int i, int j)
{
	Node T = { -INF,-INF,-INF, };
	if (i > E || j < S)return T;
	if (i <= S && j >= E)return tree[node];
	Node L = find(node * 2, S, (S + E) / 2, i, j);
	Node R = find(node * 2 + 1, (S + E) / 2 + 1, E, i, j);
	if (L.sum == -INF)return R;
	if (R.sum == -INF)return L;
	return merge(L,R);
}
int main() {
	int n,q;
	scanf("%d%d",&n,&q);
	fup(i,1,n,1)scanf("%lld",a+i);
	fup(i,1,n,1){
		ll x;
		scanf("%lld",&x);
		a[i]=x-a[i];
	}
	init(1,1,n);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		Node T=find(1,1,n,l,r);
		if(T.lmn<0 || T.sum!=0)puts("-1");
		else printf("%lld\n",T.lmx);
	}
}