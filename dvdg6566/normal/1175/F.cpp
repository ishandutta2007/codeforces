#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 300100
ll INF = 1e9;
 
int A[MAXN], P[MAXN];
int N;
 
struct node{
	node *l, *r;
	pi v;
	node(int s,int e){
		int m=(s+e)/2;
		v=mp(0,s);
		if (s != e){
			l=new node(s,m);r=new node(m+1,e);
		}
	}
	void up(int s, int e, int x, int val){
		int m=(s+e)/2;
		if (s==e){
			v.f=val;
			return;
		}
		if (x <= m)l->up(s,m,x,val);
		else r->up(m+1,e,x,val);
		v = cmp(l->v,r->v);
	}
	pi query(int s, int e, int x, int y){
		int m=(s+e)/2;
		if (s==x&&e==y)return v;
		if (x > m)return r->query(m+1,e,x,y);
		else if (y <= m)return l->query(s,m,x,y);
		return cmp(l->query(s,m,x,m),r->query(m+1,e,m+1,y));
	}
	pi cmp(pi a, pi b){
		if (a.f > b.f)return a;
		return b;
	}
}*root;
 
struct node2{
	node2 *l, *r;
	pi v;
	node2(int s,int e){
		int m=(s+e)/2;
		v=mp(INF,s);
		if (s != e){
			l=new node2(s,m);r=new node2(m+1,e);
		}
	}
	void up(int s, int e, int x, int val){
		int m=(s+e)/2;
		if (s==e){
			v.f=val;
			return;
		}
		if (x <= m)l->up(s,m,x,val);
		else r->up(m+1,e,x,val);
		v = cmp(l->v,r->v);
	}
	pi query(int s, int e, int x, int y){
		int m=(s+e)/2;
		if (s==x&&e==y)return v;
		if (x > m)return r->query(m+1,e,x,y);
		else if (y <= m)return l->query(s,m,x,y);
		return cmp(l->query(s,m,x,m),r->query(m+1,e,m+1,y));
	}
	pi cmp(pi a, pi b){
		if (a.f < b.f)return a;
		return b;
	}
}*minroot;
 
bool uniquenums(int x, int y){
	int t = minroot->query(1,N,x,y).f;
	if (t > y)return 1;
	return 0;
}
 
int ans;
 
void dnc(int s,int e){
	// cout<<s<<' '<<e<<'\n';
	if (e==s){
		if (A[s]==1)++ans;
		return;
	}
	pi cur = root->query(1,N,s,e);
	int ind = cur.s;
	int leftd = ind-s;
	int rightd = e-ind;
 
	int len = cur.f;
 
	for (int x = max(s+len-1, ind); x <= e; ++x){
		int y = x-len+1;
		// cout<<x<<' '<<y<<' '<<cur.f<<' '<<uniquenums(y,x)<<'\n';
		if (uniquenums(y,x))++ans;
	}
 
	if (ind != e)dnc(ind+1,e);
	if (ind != s)dnc(s,ind-1);
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	// freopen("in.txt","r",stdin);
	cin>>N;
	for (int i=1;i<=N;++i)cin>>A[i];
	root = new node(1,N);
	minroot = new node2(1,N);
	for (int i=1;i<=N;++i)P[i]=N+1;
	for (int i=N;i>0;--i){
		int n = P[A[i]];
		P[A[i]] = i;
		minroot->up(1,N,i, n);
	}
	for (int i=1;i<=N;++i)root->up(1,N,i,A[i]);
	dnc(1,N);
	cout<<ans;
}