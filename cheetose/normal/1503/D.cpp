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

iii p[200001];
int a[400004];
Vi v[200001],V[200001];
int col[200001];
int c[2];
void dfs(int N,int cc){
	col[N]=cc;
	c[cc]++;
	for(int next:v[N]){
		if(col[next]==-1){
			dfs(next,cc^1);
		}
	}
	for(int next:V[N]){
		if(col[next]==-1){
			dfs(next,cc);
		}
	}
}
int main() {
	MEM_1(col);
	int n;
	scanf("%d",&n);
	fup(i,1,n,1){
		int x,y,t=0;
		scanf("%d%d",&x,&y);
		if(x>y){
			t=1;
			swap(x,y);
		}
		if(x>n || y<=n)return !printf("-1\n");
		p[i]=iii(x,y,t);
	}
	sort(p+1,p+n+1);
	fup(i,1,n,1){
		auto [x,y,t]=p[i];
		a[y]=x;
		if(t)a[y]=-a[y];
	}
	VPi v1;
	fup(i,n+1,2*n,1){
		if(a[i]>0)v1.pb({a[i],1});
		else v1.pb({-a[i],-1});
	}
	Vi vv;
	for(auto P:v1){
		auto it=lower_bound(ALL(vv),P.X);
		if(it==vv.end())vv.pb(P.X);
		else *it=P.X;
	}
	if(vv.size()>2)return !printf("-1\n");
	set<Pi> S1;
	for(Pi P:v1){
		for(Pi pp:S1){
			if(pp.X>=P.X)break;
			if(pp.Y*P.Y<0){
				V[pp.X].pb(P.X);
				V[P.X].pb(pp.X);
			}else{
				v[pp.X].pb(P.X);
				v[P.X].pb(pp.X);
			}
		}
		S1.insert(P);
	}
	int ans=0;
	fup(i,1,n,1){
		if(col[i]==-1){
			c[0]=c[1]=0;
			dfs(i,0);
			ans+=min(c[0],c[1]);
		}
	}
	printf("%d\n",ans);
}