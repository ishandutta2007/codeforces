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

Pi p[2000],q[2000];
int mx[1000001];
int main() {
	MEM_1(mx);
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)scanf("%d%d",&p[i].X,&p[i].Y);
	fup(i,0,m-1,1)scanf("%d%d",&q[i].X,&q[i].Y);
	sort(q,q+m);
	VPi v,vv;
	fup(i,0,m-1,1){
		if(v.empty())v.pb(q[i]);
		else{
			while(!v.empty() && v.back().Y<=q[i].Y)v.pop_back();
			v.pb(q[i]);
		}
	}
	int M=v.size();
	vv.pb(mp(0,v[0].Y+1));
	fup(i,0,M-2,1){
		vv.pb(mp(v[i].X+1,v[i+1].Y+1));
	}
	VPi V;
	vv.pb(mp(v[M-1].X+1,0));
	fup(i,0,n-1,1){
		int t=lower_bound(ALL(vv),mp(p[i].X,INF))-vv.begin()-1;
		mx[0]=max(mx[0],vv[t].Y-p[i].Y);
		int pr=vv[t].Y-p[i].Y;
		fup(j,t+1,(int)vv.size()-1,1){
			int x=vv[j].X-p[i].X,y=max(0,vv[j].Y-p[i].Y);
			mx[x-1]=max(mx[x-1],pr);
			mx[x]=max(mx[x],y);
			pr=y;
		}
	}
	int ans=1000001,t=0;
	fdn(i,1000000,0,1){
		t=max(t,mx[i]);
		ans=min(ans,i+t);
	}
	printf("%d\n",ans);
}