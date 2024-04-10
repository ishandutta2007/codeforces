#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
const int MAXN=210000;
const int MAXK=19;
const int INF = 1e9;
const ll MOD = 998244353;

vi V[MAXN];
int N,a,b,Q;
vi qry;
int RQ;

pi ask(){
	++RQ;
	assert(RQ<=12);
	cout<<"? "<<SZ(qry)<<' ';
	for (auto i:qry)cout<<i<<' ';
	cout<<'\n';
	cout<<flush;
	int a,b;
	cin>>a>>b;
	return mp(a,b);
}

vi layers[MAXN];
int d[MAXN];

void dfs(int x, int p){
	layers[d[x]].pb(x);
	for (auto v:V[x])if(v!=p){
		d[v]=d[x]+1;
		dfs(v,x);
	}
}

void solve(){
	qry.clear();
	for(int i=1;i<=N;++i)qry.pb(i);
	for(int i=1;i<=N;++i)layers[i].clear();
	pi x = ask();
	int rt = x.f;	
	int ds = x.s;
	d[rt]=0;
	dfs(rt,-1);
	int l = (ds+1)/2-1;
	int u = min(ds+1,*max_element(d,d+N+1));
	while(u>l){
		int m = (l+u+1)/2;
		qry.clear();
		for (auto t:layers[m])qry.pb(t);
		pi x = ask();
		if(x.s == ds)l=m;
		else u=m-1;
	}
	qry.clear();
	for (auto t:layers[l])qry.pb(t);
	pi t = ask();
	for(int i=1;i<=N;++i)layers[i].clear();
	d[t.f]=0;
	dfs(t.f,-1);
	qry.clear();
	for (auto t:layers[ds])qry.pb(t);
	pi r = ask();
	cout<<"! "<<t.f<<' '<<r.f<<'\n'<<flush;
	string S;cin>>S;
}

int main(){
  cin>>Q;
  while(Q--){
  	RQ=0;
  	cin>>N;
  	for(int i=1;i<=N;++i)V[i].clear();
  	for(int i=1;i<N;++i){
  		cin>>a>>b;
  		V[a].pb(b);
  		V[b].pb(a);
  	}
  	solve();
  }
}