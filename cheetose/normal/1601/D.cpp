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

int tree[1<<21];

void init(int node, int S, int E){
	tree[node]=INF;
	if (S == E)return;
	init(node*2,S,(S+E)/2);
	init(node*2+1,(S+E)/2+1,E);
}
void upd(int node, int S, int E, int k, int dif){
	if (S == E){
		tree[node]=min(tree[node],dif);
		return;
	}
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
	tree[node]=min(tree[node*2],tree[node*2+1]);
}

int find(int node, int S, int E, int i, int j){
	if (i > E || j < S)return INF;
	if (i <= S && j >= E)return tree[node];
	return min(find(node * 2, S, (S + E) / 2, i, j), find(node * 2 + 1, (S + E) / 2 + 1, E, i, j));
}
int main(){
	int n,d;
	scanf("%d%d",&n,&d);
	Vi vv;
	vv.pb(d);
	VPi p;
	fup(i,0,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<d)continue;
		p.pb(mp(x,y));
		vv.pb(x);
		vv.pb(y);
	}
	n=p.size();
	COMPRESS(vv);
	int N=vv.size();
	d=lower_bound(ALL(vv),d)-vv.begin();
	fup(i,0,n-1,1){
		p[i].X=lower_bound(ALL(vv),p[i].X)-vv.begin();
		p[i].Y=lower_bound(ALL(vv),p[i].Y)-vv.begin();
	}
	init(1,0,N-1);
	int ans=0;
	fup(i,0,n-1,1){
		if(p[i].Y<=p[i].X){
			ans++;
			upd(1,0,N-1,p[i].Y,p[i].X);
		}
	}
	VPi V;
	fup(i,0,n-1,1){
		if(p[i].Y>p[i].X){
			if(find(1,0,N-1,p[i].X+1,p[i].Y-1)>=p[i].Y)V.pb(p[i]);
		}
	}
	sort(ALL(V),[&](Pi p1,Pi p2){return p1.Y<p2.Y;});
	int now=d;
	for(auto [x,y]:V){
		if(x>=now){
			ans++;
			now=max(now,y);
		}
	}
	printf("%d\n",ans);
}