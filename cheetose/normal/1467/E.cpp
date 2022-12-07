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

Vi v[250005],V[250005];
int a[250005],depth[250005],parent[250005];
int S[250005],E[250005],cnt[250005],cc;
void dfs(int N,int p=-1,int d=0){
	depth[N]=d;
	S[N]=++cc;
	parent[N]=p;
	V[a[N]].pb(cc);
	for(int next:v[N]){
		if(next==p)continue;
		dfs(next,N,d+1);
	}
	E[N]=cc;
}
bool dfs2(int N,int p=-1){
	if(cnt[a[N]])return 0;
	cnt[a[N]]++;
	for(int next:v[N]){
		if(next==p)continue;
		if(!dfs2(next,N))return 0;
	}
	cnt[a[N]]--;
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	Vi vv;
	fup(i,1,n,1)scanf("%d",a+i),vv.pb(a[i]);
	COMPRESS(vv);
	fup(i,1,n,1)a[i]=lower_bound(ALL(vv),a[i])-vv.begin();
	fup(i,1,n-1,1){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	int dd=0,r=1,ok=0;
	fup(i,1,n,1){
		int t=upper_bound(ALL(V[a[i]]),E[i])-lower_bound(ALL(V[a[i]]),S[i]);
		if(t!=1){
			ok=1;
			if(depth[i]>dd){
				dd=depth[i],r=i;
			}
		}
	}
	if(ok){
		fup(i,1,n,1){
			if(parent[i]==r && upper_bound(ALL(V[a[r]]),E[i])-lower_bound(ALL(V[a[r]]),S[i])){
				r=i;
				break;
			}
		}
	}
	bool res=dfs2(r);
	Vi ans;
	if(res){
		fup(i,1,n,1)cnt[i]=0;
		queue<int> q;
		cnt[r]=1;
		ans.pb(r);
		q.push(r);
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(int next:v[x]){
				if(!cnt[next] && V[a[next]].size()==1){
					cnt[next]=1;
					ans.pb(next);
					q.push(next);
				}
			}
		}
	}
	printf("%d\n",ans.size());
}