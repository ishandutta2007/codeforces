#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end() 
#define SZ(x) (ll)x.size()
#define f first
#define s second
const int MAXN=200100;
const int MAXK=18;
const ll INF = 1e9;
const ll MOD = 1e9+7;

ll N,M,K,R,C,a,b,c,OX;
vpi V[MAXN];
ll res[MAXN];
pi A[MAXN];
priority_queue<pi,vector<pi>,greater<pi>>pq;

struct node{
	pi v;
	int s,e,m;
	node *l,*r;
	node(int _s,int _e):s(_s),e(_e){
		m=(s+e)/2;v=mp(0,-1);
		if(s!=e){
			l=new node(s,m);r=new node(m+1,e);
		}
	}
	void up(int x,pi val){
		if(s==e){
			v=max(v,val);return;
		}
		if(x<=m)l->up(x,val);
		else r->up(x,val);
		v=max(l->v,r->v);
	}
	pi query(int x,int y){
		if(s==x&&e==y)return v;
		if(y<=m)return l->query(x,y);
		else if(x>m)return r->query(x,y);
		else return max(l->query(x,m),r->query(m+1,y));
	}
}*root;

typedef pair<pi,pi> pp;
vector<pp> S;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a>>b;
		V[a].pb(b,i+1);
		A[i+1]=mp(a,b);
	}
	for(int i=1;i<=N;++i){
		for(auto k:V[i]){
			pq.push(k);
		}
		pi t=pq.top();pq.pop();
		res[t.s]=i;
	}
	for(int i=1;i<=N;++i){
		S.pb(mp(res[i],i),A[i]);
	}
	root=new node(1,N);
	sort(ALL(S));
	pi flip=mp(-1,-1);
	for(auto i:S){
		// cout<<"Solution index "<<i.f.f<<'\n';
		// cout<<"Range "<<i.s.f<<' '<<i.s.s<<'\n';
		pi x=root->query(i.s.f,i.s.s);
		if(x.s!=-1&&x.f>=i.f.f){
			flip=mp(i.f.s,x.s);
			break;
		}
		root->up(i.f.f, mp(i.s.s, i.f.s));
	}
	if(flip.f==-1){
		cout<<"YES\n";
		for(int i=1;i<=N;++i)cout<<res[i]<<' ';
	}else{
		cout<<"NO\n";
		for(int i=1;i<=N;++i)cout<<res[i]<<' ';cout<<'\n';
		swap(res[flip.f],res[flip.s]);
		for(int i=1;i<=N;++i)cout<<res[i]<<' ';cout<<'\n';
	}
}