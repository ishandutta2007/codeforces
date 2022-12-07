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

struct A{
	ll oddmn,evenmn;
}tree[524288];
ll d[200005];
ll lazyeven[524288],lazyodd[524288];
A merge(const A &L,const A &R){
	A res=L;
	res.oddmn=min(res.oddmn,R.oddmn);
	res.evenmn=min(res.evenmn,R.evenmn);
	return res;
}
void init(int node,int S,int E){
	if(S==E){
		tree[node]={INF,INF};
		if(S&1)tree[node].oddmn=d[S];
		else tree[node].evenmn=d[S];
		return;
	}
	init(node*2,S,(S+E)/2);
	init(node*2+1,(S+E)/2+1,E);
	tree[node]=merge(tree[node*2],tree[node*2+1]);
}
void propagation(int node, int S, int E)
{
	if (lazyeven[node] != 0)
	{
		if(S==E){
			if(S%2==0)tree[node].evenmn+=lazyeven[node];
		}else{
			tree[node].evenmn+=lazyeven[node];
			lazyeven[node*2]+=lazyeven[node];
			lazyeven[node*2+1]+=lazyeven[node];
		}
		lazyeven[node]=0;
	}
	if (lazyodd[node] != 0)
	{
		if(S==E){
			if(S&1)tree[node].oddmn+=lazyodd[node];
		}else{
			tree[node].oddmn+=lazyodd[node];
			lazyodd[node*2]+=lazyodd[node];
			lazyodd[node*2+1]+=lazyodd[node];
		}
		lazyodd[node]=0;
	}
}
void upd(int node, int S, int E, int i, int j, int type, ll val)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		if(type==0)lazyodd[node]+=val;
		else lazyeven[node]+=val;
		propagation(node, S, E);
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j, type, val);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, type, val);
	tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}
A find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return {INF,INF};
	if (j >= E && i <= S) return tree[node];
	A L=find(node * 2, S, (S + E) / 2, i, j),R=find(2 * node + 1, (S + E) / 2 + 1, E, i, j);
	if(L.oddmn==INF && L.evenmn==INF)return R;
	if(R.oddmn==INF && R.evenmn==INF)return L;
	return merge(L,R);
}
int main(){
	int n;
	scanf("%d", &n);
	fup(i,1,n,1){
		scanf("%lld",d+i);
		d[i]-=d[i-1];
	}
	init(1,0,n);
	int q;
	scanf("%d",&q);
	while(q--){
		int o,x,y;
		ll z;
		scanf("%d%d%d",&o,&x,&y);
		x++,y++;
		if(o==1){
			scanf("%lld",&z);
			if(x&1){
				upd(1,0,n,x,y,0,z);
				if((y-x)%2==0){
					upd(1,0,n,y+1,n,0,z);
					upd(1,0,n,y+1,n,1,-z);
				}
			}else{
				upd(1,0,n,x,y,1,z);
				if((y-x)%2==0){
					upd(1,0,n,y+1,n,0,-z);
					upd(1,0,n,y+1,n,1,z);
				}
			}
		}else{
			A t=find(1,0,n,x-1,x-1);
			ll r=min(t.evenmn,t.oddmn);
			A T=find(1,0,n,x,y);
			if(x&1){
				if(T.oddmn<1-r || T.evenmn<r){
					puts("0");
					continue;
				}
			}else{
				if(T.oddmn<r || T.evenmn<1-r){
					puts("0");
					continue;
				}
			}
			t=find(1,0,n,y,y);
			ll r2=min(t.evenmn,t.oddmn);
			if((x&1)==(y&1)){
				if(r2+r==1)puts("1");
				else puts("0");
			}else{
				if(r2-r==0)puts("1");
				else puts("0");
			}
		}
	}
}