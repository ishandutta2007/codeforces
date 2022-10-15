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
const ll MAXN = 1100;
const ll INF = 1e9;
const ll MOD = 1e9+7;

ll N,Q,a,b,c,d,e,M,X,T;
int A[MAXN];
int B[MAXN];
vi V[MAXN];
int p[MAXN];

void dfs(int x,int pa){
	p[x]=pa;
	for(auto v:V[x])if(v!=pa)dfs(v,x);
}

int main(){
	// freopen("cowjog.in","r",stdin);
	// freopen("cowjog.out","w",stdout);
	// ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=1;i<=N;++i)V[i].clear();
		for(int i=1;i<N;++i){
			cin>>a>>b;V[a].pb(b);V[b].pb(a);
		}
		memset(A,0,sizeof(A));memset(B,0,sizeof(B));
		cin>>a; for(int i=0;i<a;++i){cin>>b;A[b]=1;}
		int nrt =b;
		cin>>a; for(int i=0;i<a;++i){cin>>b;B[b]=1;}
		int rt = b;
		cout<<"B "<<rt<<endl;cin>>c;
		if(A[c]){
			cout<<"C "<<c<<endl;continue;
		}
		dfs(nrt,-1);
		vi t;
		int cur=c;while(cur!=nrt){t.pb(cur);cur=p[cur];}
		t.pb(nrt);
		// for(auto x:t)cout<<x<<' ';cout<<'\n';
		while(SZ(t)>1&&A[t[SZ(t)-2]])t.pop_back();
		int tt = t.back();

		// for(int i=1;i<=N;++i)cout<<B[i];cout<<'\n';
		cout<<"A "<<tt<<endl;cin>>c;
		if(B[c]){
			cout<<"C "<<tt<<endl;
		}else{
			cout<<"C "<<-1<<endl;
		}
	}
}