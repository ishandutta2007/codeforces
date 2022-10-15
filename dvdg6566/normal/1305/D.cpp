#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 1010;

ll T,Q,N,M,a,b,c,d,e,f;
ll A[MAXN];
ll B[MAXN];
vi V[MAXN];
string S;
vi open, close;
int blk[MAXN];
ll dst[MAXN];
ll p[MAXN];

void dfs(ll x, ll par){
	for (auto v:V[x])if(v!=par && !blk[v]){
		dst[v] = dst[x] + 1;
		p[v] = x;
		dfs(v,x);
	}
}
stack<int> st;

void dfs2(ll x, ll p, ll bl){
	if (x == bl)return;
	st.push(x);
	for (auto v:V[x])if (!blk[v] && v!=p)dfs2(v,x,bl);
}

int query(int x, int y){
	cout<<"? "<<x<<' '<<y<<'\n'<<flush;
	int t;cin>>t;
	return t;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for (int i=1;i<N;++i){
		cin>>a>>b;
		V[a].pb(b);
		V[b].pb(a);
	}
	ll E=N;
	while (E>1){
		memset(dst,-1,sizeof(dst));
		memset(p,0,sizeof(p));
		ll t = 1;
		while (blk[t])++t;
		// for (int i=1;i<=N;++i)cout<<blk[i]<<' ';cout<<'\n';
		dst[t] = 0;
		dfs(t,-1);
		int furthest = max_element(dst+1,dst+N+1)-dst;
		t = furthest;
		memset(dst,-1,sizeof(dst));
		memset(p,0,sizeof(p));
		dst[t] = 0;
		dfs(t,-1);
		// for (int i=1;i<=N;++i)cout<<dst[i]<<' ';cout<<'\n';
		furthest = max_element(dst+1,dst+N+1)-dst;
		// cout<<t<<' '<<furthest<<'\n';
		ll c = query(furthest, t);
		dfs2(t,-1,c);
		dfs2(furthest,-1,c);
		while(SZ(st)){
			int t = st.top();st.pop();
			blk[t] = 1;--E;
		}
	}
	cout<<"! "<<min_element(blk+1,blk+N+1)-blk;
}