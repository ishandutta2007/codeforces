#include <bits/stdc++.h>
#include <ext/rope>
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
using namespace __gnu_cxx;
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
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int n,N;
LLL a[500000];
Vll vv;
Pll tree[524288<<2];
ll lazy[524288<<2];
void init(int node, int S, int E)
{
	if (S == E)
	{
		tree[node] = mp(vv[S],vv[S]);
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
void propagation(int node, int S, int E)
{
	if (lazy[node] != 0)
	{
		tree[node].X = tree[node].X+lazy[node];
		if (S != E)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void upd(int node, int S, int E, int i, int j, ll val)
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
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
Pll find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return mp(-INF,-INF);
	if (j >= E && i <= S) return tree[node];
	return max(find(node * 2, S, (S + E) / 2, i, j), find(2 * node + 1, (S + E) / 2 + 1, E, i, j));
}
int main() {
	scanf("%d",&n);
	fup(i,0,n-1,1){
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		if(x>y)swap(x,y);
		a[i]=LLL(x,y,z);
		vv.pb(x);vv.pb(y);
	}
	sort(ALL(vv));vv.resize(unique(ALL(vv))-vv.begin());
	fup(i,0,n-1,1){
		auto &[x,y,z]=a[i];
		x=lower_bound(ALL(vv),x)-vv.begin();
		y=lower_bound(ALL(vv),y)-vv.begin();
	}
	sort(a,a+n,[&](LLL l1,LLL l2){
		return get<1>(l1)<get<1>(l2);
	});
	ll ans=0,l=(ll)2e9,r=(ll)2e9;
	N=vv.size();
	init(1,0,N-1);
	for(int i=0;i<n;){
		int t=i;
		while(t<n && get<1>(a[i])==get<1>(a[t])){
			auto [x,y,z]=a[t];
			upd(1,0,N-1,0,x,z);
			t++;
		}
		ll c=get<1>(a[i]);
		Pll tmp=find(1,0,N-1,0,c);
		if(tmp.X-vv[c]>ans){
			ans=tmp.X-vv[c];
			l=tmp.Y;
			r=vv[c];
		}
		i=t;
	}
	printf("%lld\n",ans);
	printf("%lld %lld %lld %lld\n",l,l,r,r);
}