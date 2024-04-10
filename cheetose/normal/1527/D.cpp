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

Vi v[200005];
int sz[200005],par[200005];
ll cnt[200005],ans[200005],cc[200005];
bool chk[200005],leaf[200005];
void dfs(int N,int p=-1,int k=-1){
	sz[N]=1;
	par[N]=p;
	cc[N]=k;
	for(int next:v[N]){
		if(next==p)continue;
		int nk=N==0?next:k;
		dfs(next,N,nk);
		sz[N]+=sz[next];
	}
}
void solve(){
	int n;
	scanf("%d",&n);cnt[n]=0;
	fup(i,0,n-1,1){
		v[i].clear();
		cnt[i]=chk[i]=leaf[i]=0;
	}
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(0);
	ll t=1;
	for(int next:v[0]){
		cnt[0]+=t*sz[next];
		t+=sz[next];
	}
	chk[0]=leaf[0]=1;
	set<int> S;
	S.insert(0);
	fup(i,1,n-1,1){
		if(!chk[i]){
			chk[i]=1;
			leaf[i]=1;
			S.insert(i);
			int now=par[i];
			while(now!=-1){
				if(chk[now]){
					if(i>1 && leaf[now]){
						leaf[now]=0;
						S.erase(now);
					}
					break;
				}else chk[now]=1;
				now=par[now];
			}
		}
		if(S.size()>2)break;
		Vi vv;
		for(int x:S)vv.pb(x);
		int x=vv[0],y=vv[1];
		if(x==0){
			cnt[i]=1ll*sz[y]*(n-sz[cc[y]]);
		}else{
			cnt[i]=1ll*sz[x]*sz[y];
		}
	}
	ll tot=1ll*n*(n-1)/2;
	fdn(i,n,1,1){
		ans[i]=cnt[i-1]-cnt[i];
		tot-=ans[i];
	}
	ans[0]=tot;
	fup(i,0,n,1)printf("%lld ",ans[i]);
	puts("");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}