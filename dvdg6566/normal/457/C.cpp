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
const int MAXN=100001;
const ll MOD=998244353;
const int MAXL = 8000100;
const ll INF = 1e18;

int N,a,b,c;
vi V[MAXN];
int R;
ll ans;
priority_queue<pi> pq;

struct node{
	int s,e,m,v,c;
	node *l,*r;
	node(int _s,int _e):s(_s),e(_e),v(0),c(0){
		m=(s+e)/2;
		if(s!=e){
			l=new node(s,m);r=new node(m+1,e);
		}
	}
	void ins(int x,int t){
		assert(x<=e&&x>=s);
		if(s==e){
			c+=t;
			v+=t*x;
			return;
		}
		if(x<=m)l->ins(x,t);
		else r->ins(x,t);
		v=l->v+r->v;c=l->c+r->c;
	}
	int ask(int w){
		if(w==c)return v;
		if(s==e){
			return w*s;
		}
		if(l->c>=w)return l->ask(w);
		else return r->ask(w-l->c)+l->v;
	}
	void db(){
		if(s==e){
			if(s<=10)cout<<v<<' '<<c<<'\n';
		}
		else {l->db();r->db();}
	}
}*root;

int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a>>b;
		if(a==0||b==0)++R;
		else V[a].pb(b);
	}
	root=new node(0,100000);
	for(int i=0;i<MAXN;++i)if(SZ(V[i])){
		pq.push(mp(SZ(V[i]), i));
		sort(ALL(V[i]));reverse(ALL(V[i]));
		for(auto t:V[i]){
			root->ins(t,1);
		}
	}
	int ans=1e9;
	int runcst=0;
	for(int votes=N;votes>0;--votes){
		// cerr<<"Votes "<<votes<<'\n';
		while(SZ(pq) && pq.top().f > votes-1){
			pi t=pq.top();pq.pop();
			// cerr<<"Buy "<<V[t.s].back()<<'\n';
			root->ins(V[t.s].back(),-1);
			runcst += V[t.s].back();V[t.s].pop_back();
			++R;
			if(SZ(V[t.s]))pq.push(mp(SZ(V[t.s]),t.s));
		}
		// root->db();
		int needs=votes-R;
		// cerr<<needs<<'\n';
		int r=runcst;
		if(needs)r+=root->ask(needs);
		ans=min(ans,r);
	}
	cout<<ans;
}