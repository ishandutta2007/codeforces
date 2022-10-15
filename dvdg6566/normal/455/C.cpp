#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
const int MAXN=300001;
const ll MOD=998244353;
const int MAXL = 8000100;
const ll INF = 1e18;

int d[MAXN];
vi cur;
int p[MAXN];
int par(int x){return (p[x]==x)?x:p[x]=par(p[x]);}
int N,E,a,b,c,Q;
vi V[MAXN];

void dfs(int x,int p){
	cur.pb(x);
	for(auto v:V[x])if(v!=p){d[v]=d[x]+1;dfs(v,x);}
}

void fd(int x){
	cur.clear();
	dfs(x,-1);
	int f=-1;
	int md=-1;
	for(auto i:cur)if(d[i]>md){f=i;md=d[i];}
	d[f]=0;
	dfs(f,-1);
	md=-1;
	for(auto i:cur)md=max(md,d[i]);
	d[x]=md;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>E>>Q;
	for(int i=1;i<=N;++i)p[i]=i;
	while(E--){
		cin>>a>>b;
		V[a].pb(b);V[b].pb(a);
		p[par(a)]=par(b);
	}
	for(int i=1;i<=N;++i)if(par(i)==i){
		fd(i);
	}
	while(Q--){
		cin>>a;
		if(a==1){
			cin>>b;
			cout<<d[par(b)]<<'\n';
		}else{
			cin>>a>>b;
			a=par(a);b=par(b);
			if(a==b)continue;
			d[a]=d[b]=max({d[a],d[b],(d[a]+1)/2+(d[b]+1)/2+1});
			p[a]=b;
		}
	}
}