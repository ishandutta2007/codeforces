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
#define ub upper_bound
const int MAXN=500100;

ll A[MAXN];
ll N,M,K,Q,a,b,c,d;
ll B[MAXN];
vi V[MAXN];
ll T;
ll da,db;
ll dx[MAXN];
void dfs(int x,int p){
	for(auto v:V[x])if(v!=p){
		dx[v]=dx[x]+1;
		dfs(v,x);
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>a>>b>>da>>db;

		for(int i=1;i<=N;++i)V[i].clear();
		for(int i=1;i<N;++i){
			cin>>c>>d;
			V[c].pb(d);
			V[d].pb(c);
		}
		dx[b]=0;
		ll f=0;
		ll fn=0;
		dfs(b,-1);

		if(dx[a]<=da){
			cout<<"Alice\n";
			continue;
		}

		for(int i=1;i<=N;++i){
			if(dx[i]>f){
				fn=i;
				f=dx[i];
			}
		}
		dx[fn]=0;
		f=0;
		dfs(fn,-1);
		for(int i=1;i<=N;++i)f=max(f,dx[i]);


		db=min(db,f);
		// cerr<<db<<' '<<da<<'\n';

		if(da*2>=db){
			cout<<"Alice\n";
			continue;
		}
		

		

		cout<<"Bob\n";
	}
}