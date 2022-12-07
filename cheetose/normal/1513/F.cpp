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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll a[200000],b[200000];
int tree[1050000];

void init(int node, int S, int E){
	if (S == E){
		tree[node] = INF;
		return;
	}
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void upd(int node, int S, int E, int k, int dif){
	if (S == E){
		tree[node]=min(tree[node],dif);
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int find(int node, int S, int E, int i, int j){
	if (i > E || j < S)return INF;
	if (i <= S && j >= E)return tree[node];
	return min(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
void upd2(int node, int S, int E, int k, int dif){
	if (S == E){
		tree[node]=max(tree[node],dif);
		return;
	}
	if (k <= (S + E) / 2)upd2(node * 2, S, (S + E) / 2, k, dif);
	else upd2(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int find2(int node, int S, int E, int i, int j){
	if (i > E || j < S)return -1;
	if (i <= S && j >= E)return tree[node];
	return max(find2(node * 2, S, (S + E) / 2, i, j), find2(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%lld",a+i);
	fup(i,0,n-1,1)scanf("%lld",b+i);
	VPll A,B;
	ll ans=0;
	fup(i,0,n-1,1){
		ans+=abs(a[i]-b[i]);
		if(a[i]>b[i])A.pb(mp(b[i],a[i]));
		else B.pb(mp(a[i],b[i]));
	}
	if(A.empty() || B.empty())return !printf("%lld\n",ans);
	Vll vv,v;
	for(auto [x,y]:A){
		vv.pb(x);vv.pb(y);
	}
	for(auto [x,y]:B){
		v.pb(x);v.pb(y);
	}
	COMPRESS(vv);
	COMPRESS(v);
	int N=vv.size(),M=v.size();
	init(1,0,N-1);
	for(auto [x,y]:A){
		x=lower_bound(ALL(vv),x)-vv.begin();
		y=lower_bound(ALL(vv),y)-vv.begin();
		upd(1,0,N-1,y,x);
	}
	ll tmp=0;
	for(auto [x,y]:B){
		int t=lower_bound(ALL(vv),y)-vv.begin();
		int r=find(1,0,N-1,t,N-1);
		if(r==INF)continue;
		ll z=vv[r];
		tmp=max(tmp,y-max(x,z));
	}
	init(1,0,M-1);
	for(auto [x,y]:B){
		x=lower_bound(ALL(v),x)-v.begin();
		y=lower_bound(ALL(v),y)-v.begin();
		upd(1,0,M-1,y,x);
	}
	for(auto [x,y]:A){
		int t=lower_bound(ALL(v),y)-v.begin();
		int r=find(1,0,M-1,t,M-1);
		if(r==INF)continue;
		ll z=v[r];
		tmp=max(tmp,y-max(x,z));
	}
	printf("%lld\n",ans-2*tmp);
}