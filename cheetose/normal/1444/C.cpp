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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

Vi v[500005],CC[500005],vv;
VPi C[500005];
int a[500005];
int parent[1000005],cc;
Pi edge[500005];
int com[500005];
int find(int x){
	if(parent[x]==x)return x;
	return parent[x]=find(parent[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x!=y){
		parent[x]=y;
		vv.pb(x);
	}
}
void roll(){
	while(!vv.empty()){
		int t=vv.back();
		vv.pop_back();
		parent[t]=t;
	}
}
map<Pi,int> M;
int col[500005];
bool chk[500005],killed[500005];
void dfs(int N){
	chk[N]=1;
	for(int next:v[N]){
		if(a[N]!=a[next])continue;
		if(chk[next] && col[N]==col[next])killed[a[N]]=1;
		if(!chk[next]){
			col[next]=col[N]^1;
			com[next]=com[N];
			dfs(next);
		}
	}
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,1000002,1)parent[i]=i;
	fup(i,1,m,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
		int t1=a[x],t2=a[y];
		if(t1>t2)swap(t1,t2);
		if(t1!=t2){
			int c;
			if(M.count(mp(t1,t2)))c=M[mp(t1,t2)];
			else{
				c=++cc;
				M[mp(t1,t2)]=c;
				edge[c]=mp(t1,t2);
			}
			C[c].pb(mp(x,y));
		}
	}
	int tt=0;
	fup(i,1,n,1){
		if(!chk[i]){
			com[i]=++tt;
			CC[a[i]].pb(tt);
			dfs(i);
		}
	}
	ll ans=0;
	fup(i,1,k,1)if(!killed[i])ans++;
	ans=ans*(ans-1)/2;
	fup(i,1,cc,1){
		int a=edge[i].X,b=edge[i].Y;
		if(killed[a] || killed[b])continue;
		for(auto [p,q]:C[i]){
			int x=com[p],y=com[q];
			if(col[p]!=col[q]){
				merge(2*x, 2*y);
				merge(2*x+1,2*y+1);
			}else{
				merge(2*x,2*y+1);
				merge(2*x+1,2*y);
			}
		}
		int tt=0;
		for(int x:CC[a]){
			if(find(2*x)==find(2*x+1))tt=1;
		}
		for(int x:CC[b]){
			if(find(2*x)==find(2*x+1))tt=1;
		}
		ans-=tt;
		roll();
	}
	printf("%lld\n",ans);
}