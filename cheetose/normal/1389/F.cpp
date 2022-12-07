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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

struct A{
	int l,r,t;
}a[200001];
vector<A> L,R;
Vi Lres,Rres;
struct seg{
	int tree[1050000]={0},lazy[1050000]={0};
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
		tree[node] = max(tree[2 * node],tree[2 * node + 1]);
	}
	int find(int node, int S, int E, int i, int j)
	{
		propagation(node, S, E);
		if (i > E || j < S) return 0;
		if (j >= E && i <= S) return tree[node];
		return max(find(node * 2, S, (S + E) / 2, i, j), find(2 * node + 1, (S + E) / 2 + 1, E, i, j));
	}
}Ltree,Rtree;
int main(){
	L.pb({0,0,0});R.pb({0,0,0});
	Lres.pb(0);Rres.pb(0);
	int n;
	scanf("%d",&n);
	fup(i,1,n,1){
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].t);
	}
	sort(a+1,a+n+1,[&](A a1,A a2){
		return a1.r<a2.r;
	});
	fup(i,1,n,1){
		if(a[i].t==1)L.pb(a[i]),Lres.pb(0);
		else R.pb(a[i]),Rres.pb(0);
	}
	int N=L.size(),M=R.size();
	int ii=0,jj=0;
	fup(i,1,n,1){
		if(a[i].t==1){
			ii++;
			int l=0,r=jj;
			while(l<=r){
				int k=l+r>>1;
				if(R[k].r<a[i].l)l=k+1;
				else r=k-1;
			}
			Rtree.upd(1,0,M-1,0,r,1);
			Lres[ii]=Rtree.find(1,0,M-1,0,r);
			Ltree.upd(1,0,N-1,ii,ii,Lres[ii]);
		}else{
			jj++;
			int l=0,r=ii;
			while(l<=r){
				int k=l+r>>1;
				if(L[k].r<a[i].l)l=k+1;
				else r=k-1;
			}
			Ltree.upd(1,0,N-1,0,r,1);
			Rres[jj]=Ltree.find(1,0,N-1,0,r);
			Rtree.upd(1,0,M-1,jj,jj,Rres[jj]);
		}
	}
	int ans=0;
	fup(i,0,ii,1)ans=max(ans,Lres[i]);
	fup(i,0,jj,1)ans=max(ans,Rres[i]);
	printf("%d",ans);
}