#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define emp emplace
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 5010;
const ll INF = 1e18;
const ll MOD = 1e9+7;
const ll H = 500;

vi O[MAXN];
vi E[MAXN];
vi V[MAXN];
int N,a,b,c,u,v,M,ww;
int d[MAXN];
void dfs(int x){
	if(d[x]%2==1)O[ww].pb(x);
	else E[ww].pb(x);
	for (auto v:V[x]){
		if(d[v]==-1){
			d[v]=1-d[x];
			dfs(v);
		}else if(d[v]==d[x]){
			cout<<"NO";
			exit(0);
		}
	}
}
int dp[MAXN][MAXN];
vi res;
vi out;

bool ask(int a, int b){
	if(a<0)return 0;
	if(dp[a][b]!=-1)return dp[a][b];
	if(a==0&&b==0)return 1;
	if(b==0)return 0;
	int ra=SZ(O[b]);
	int rb=SZ(E[b]);
	if (ask(a-ra,b-1)){
		res[b]=1;
		return dp[a][b]=1;
	}else if (ask(a-rb,b-1)){
		res[b]=0;
		return dp[a][b]=1;
	}else{
		return dp[a][b]=0;
	}
}
string S;

int main(){
	cin>>N;
	cin>>M;
	int A,B,C;
	cin>>A>>B>>C;
	for(int i=1;i<=M;++i){
		cin>>u>>v;
		V[u].pb(v);V[v].pb(u);
	}
	memset(d,-1,sizeof(d));
	ww=0;
	for(int i=1;i<=N;++i){
		if(d[i]==-1){
			++ww;
			d[i]=0;
			dfs(i);
			// for(int x=1;x<=N;++x)cerr<<d[x]<<' ';cout<<'\n';
		}
	}
	res.resize(ww+1,-1);
	memset(dp,-1,sizeof(dp));
	int ans=ask(B,ww);
	if(!ans){
		cout<<"NO";
		return 0;
	}
	for(int i=0;i<N;++i)out.pb(3);
	for(int i=1;i<=ww;++i){
		// cerr<<res[i]<<' ';
		if(res[i]==1)for(auto t:O[i])out[t-1]=2;
		else for(auto t:E[i])out[t-1]=2;
	}
	for(int i=0;i<N;++i){
		if(!A)break;
		if(out[i]!=3)continue;
		--A;
		out[i]=1;
	}
	cout<<"YES\n";
	for(auto x:out)cout<<x;
}