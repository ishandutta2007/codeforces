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
const int MAXN=410000;
const int MAXK=18;
const int INF = 1e9;
const ll MOD = 998244353;

set<int> S[MAXN];
int N,R,Q,a,b,c,d,e,f;

struct node{
	int s,e,m,v,lz;
	node *l,*r;
	node(int _s,int _e):s(_s),e(_e){
		m=(s+e)/2;
		lz=0;
		v=2*N-s;
		if(s!=e){l=new node(s,m);r=new node(m+1,e);v=min(l->v,r->v);}
	}
	void up(int x,int y,int val){
		if(s==x&&e==y){
			lz+=val;
			return;
		}
		if(y<=m)l->up(x,y,val);
		else if (x>m)r->up(x,y,val);
		else{
			l->up(x,m,val);
			r->up(m+1,y,val);
		}
		v=min(l->v+l->lz, r->v+r->lz);
	}
	int ask(int x,int y){
		if(s==x&&e==y)return v+lz;
		if(y<=m)return lz+l->ask(x,y);
		else if (x>m)return lz+r->ask(x,y);
		else{
			return lz+min(l->ask(x,m),r->ask(m+1,y));
		}
	}
}*root;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>R>>Q;
	multiset<int> rows;
	root=new node(1,Q+N+N);
	for(int i=0;i<Q;++i){
		cin>>a>>b;
		ll row=abs(a-R)+b;
		// cerr<<"Hi\n";
		if(S[a].find(b)!=S[a].end()){
			rows.erase(rows.find(row));
			root->up(1,row,1);
			S[a].erase(b);
		}else{
			rows.insert(row);
			root->up(1,row,-1);
			S[a].insert(b);
		}
		if(SZ(rows)==0){
			cout<<0<<'\n';
			continue;
		}
		// cerr<<"Hx\n";
		ll l=*(--rows.end());
		// cerr<<"Last "<<*(--rows.end())<<'\n';
		cout<<max(N-1-root->ask(1,l),0)<<'\n';
	}
}