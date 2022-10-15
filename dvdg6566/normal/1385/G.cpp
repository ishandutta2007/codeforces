#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end() 
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN=200100;
const ll MAXK=20;
const ll INF = 1e13;
const ll MOD = 1e9+7;

int A[MAXN];
int B[MAXN];
int sz[MAXN];
int p[MAXN];
pi T[MAXN];
int R[MAXN];
vi V[MAXN];
int L[MAXN];
int N;
int par(int x){return (p[x]==x)?x:p[x]=par(p[x]);}
vpi sames, opps;
vi od, ev;
int vis[MAXN];

void dfs(int x,int flp){
	if(vis[x])return;
	// cerr<<"DFS "<<x<<' '<<flp<<'\n';
	vis[x]=1;
	if(flp==0)od.pb(x);
	else ev.pb(x);
	for(auto v:V[x]){
		dfs(v,flp^1);
	}
}

void run(){
	opps.clear();sames.clear();
	for(int i=1;i<=N;++i){R[A[i]]++;R[B[i]]++;}
	// for(int i=1;i<=N;++i)cerr<<R[i]<<' ';cerr<<'\n';
	for(int i=1;i<=N;++i){
		if(R[i]!=2){
			cout<<-1<<'\n';
			return;
		}
	}
	for(int i=1;i<=N;++i){
		int x=A[i];
		if(T[x].f!=0){
			opps.pb(T[x].f,i);
			// cerr<<"Opposite ways "<<T[x].f<<' '<<i<<'\n';
		}else{
			T[x]=mp(i,0);
		}
	}

	for(int i=1;i<=N;++i){
		int x=B[i];
		if(T[x].f!=0){
			if(i==T[x].f)continue;
			if(T[x].s==1){
				opps.pb(T[x].f,i);
				// cerr<<"Opposite ways "<<T[x].f<<' '<<i<<'\n';
			}else{
				sames.pb(T[x].f,i);
				// cerr<<"Same "<<T[x].f<<' '<<i<<'\n';
			}
		}else{
			T[x]=mp(i,1);
		}
	}
	for(int i=1;i<=N;++i){p[i]=i;sz[i]=1;}
	for(auto i:sames){
		int a=i.f;
		int b=i.s;
		a=par(a);b=par(b);
		if(a==b)continue;
		sz[a]=sz[b]=sz[a]+sz[b];
		p[a]=b;
	}
	for(int i=1;i<=N;++i)V[i].clear();
	// for(int i=1;i<=N;++i)if(p[i]==i){
	// 	cerr<<sz[i]<<' ';
	// }
	// cerr<<'\n';
	for(auto i:opps){
		int a=par(i.f);
		int b=par(i.s);
		V[a].pb(b);V[b].pb(a);
		// cerr<<"E "<<a<<' '<<b<<'\n';
	}
	vi kp;
	vi flp;
	// for(int i=1;i<=N;++i)cerr<<par(i)<<' ';cerr<<'\n';
	for(int i=1;i<=N;++i)if(par(i)==i&&!vis[i]){
		od.clear();ev.clear();
		dfs(i,0);
		int oddl=0;
		int evenl=0;

		for(auto i:od)oddl+=sz[i];
		for(auto i:ev)evenl+=sz[i];

		if(oddl<evenl)swap(od,ev);
		// cerr<<SZ(od)<<' '<<SZ(ev)<<'\n';
		for(auto i:od)kp.pb(i);
		for(auto i:ev)flp.pb(i);
	}
	for(auto i:flp)L[i]=1;
	vi res;
	for(int i=1;i<=N;++i)if(L[par(i)]){
		res.pb(i);
	}
	cout<<SZ(res)<<'\n';
	for(auto i:res){
		cout<<i<<' ';
		swap(A[i],B[i]);
	}
	cout<<'\n';
	// cerr<<"Flip ";for(auto i:flp)cerr<<i<<' ';

	// cerr<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int X;cin>>X;
	while(X--){
		cin>>N;
		for(int i=1;i<=N;++i)cin>>A[i];
		for(int i=1;i<=N;++i)cin>>B[i];
		for(int i=1;i<=N;++i){
			R[i]=0;
			vis[i]=0;
			T[i]=mp(0,0);
			L[i]=0;
		}
		run();
		// for(int i=1;i<=N;++i)cerr<<A[i]<<' ';cerr<<'\n';
		// for(int i=1;i<=N;++i)cerr<<B[i]<<' ';cerr<<'\n';
	}
}