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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Pi p[100000];
struct SEG{
	ll tree[524288];

	void init(int node, int S, int E)
	{
		tree[node]=INF;
		if (S == E)
			return;
		init(2 * node, S, (S + E) / 2);
		init(2 * node + 1, (S + E) / 2 + 1, E);
	}

	void upd(int node, int S, int E, int k, ll dif)
	{
		if (S == E){
			tree[node]=min(tree[node],dif);
			return;
		}
		if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
		else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
		tree[node]=min(tree[node*2],tree[node*2+1]);
	}

	ll find(int node, int S, int E, int i, int j)
	{
		if (i > E || j < S)return INF;
		if (i <= S && j >= E)return tree[node];
		return min(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
	}
}A,B;
int main() {
	int n;
	scanf("%d",&n);
	Vi vv;
	ll ans=0;
	fup(i,0,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		ans+=y;
		vv.pb(x);vv.pb(x+y);
		p[i]=mp(x,y);
	}
	COMPRESS(vv);
	int N=vv.size();
	Vi t(n);
	iota(ALL(t),0);
	sort(ALL(t),[&](int a,int b){return p[a].X<p[b].X;});
	A.init(1,0,N-1);B.init(1,0,N-1);
	int w=lower_bound(ALL(vv),p[t[n-1]].X)-vv.begin();
	A.upd(1,0,N-1,w,0);B.upd(1,0,N-1,w,p[t[n-1]].X);
	fdn(ii,n-2,0,1){
		int i=t[ii];
		int x=p[i].X,y=x+p[i].Y;
		int xx=lower_bound(ALL(vv),x)-vv.begin(),yy=lower_bound(ALL(vv),y)-vv.begin();
		ll r1=A.find(1,0,N-1,xx,yy),r2=B.find(1,0,N-1,yy+1,N-1)-y;
		ll r=min(r1,r2);
		A.upd(1,0,N-1,xx,r);B.upd(1,0,N-1,xx,r+x);
		if(ii==0)ans+=r;
	}
	printf("%lld\n",ans);
}