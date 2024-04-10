#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,ll> pil;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}
void GG(){puts("-1"),exit(0);}
void clear(set<pil> &s){set<pil> t;swap(s,t);}

const ll inf=1e18;
const int N=300005;
int d[N],n,m,a,b,c;
vector<pii> q[N];
set<pil> s[N];
ll f[N],add[N];
vi e[N];

void pre(int u,int fa){
	for(auto v:e[u])
		if(v!=fa)d[v]=d[u]+1,pre(v,u);
}

void ins(int d,ll w,set<pil> &s){
	pil t=mp(d,0);
	set<pil>::iterator it=s.lower_bound(t),it2;
	if(it!=s.end()&&it->se<=w)return;
	if(it==s.end()||it->fi>d){
		if(it==s.begin()){
			s.insert(mp(d,w));
			return;
		}
		it--;
	}
	while(it->se>=w){
		int flag=(it==s.begin());
		it2=it;if(!flag)it2--;
		s.erase(it);
		if(flag)break;
		it=it2;
	}
	s.insert(mp(d,w));
}

void merge(set<pil> &s,set<pil> &t,ll &a,ll &b){
	if(t.size()>s.size())
		swap(s,t),swap(a,b);
	for(auto x:t)
		ins(x.fi,x.se+b-a,s);
	clear(t);
}

void dfs(int u,int fa){
	ll sum=0;
	for(auto v:e[u])
		if(v!=fa){
			dfs(v,u);
			sum+=f[v];
		}
	for(auto t:q[u])
		ins(t.fi,t.se+sum,s[u]);
	for(auto v:e[u])
		if(v!=fa){
			add[v]+=sum-f[v];
			merge(s[u],s[v],add[u],add[v]);
		}
	while(s[u].size()&&n-s[u].begin()->fi>=d[u])
		s[u].erase(s[u].begin());
	if(!fa){
		f[u]=sum;
		return;
	}
	if(s[u].size())f[u]=add[u]+s[u].begin()->se;
	else GG();
}

int main(){
	read(n),read(m);
	rep(i,1,n-1){
		read(a),read(b);
		e[a].pb(b),e[b].pb(a);
	}
	d[1]=1,pre(1,0);
	rep(i,1,m){
		read(a),read(b),read(c);
		q[a].pb(mp(n-d[b],c));
	}
	dfs(1,0);
	printf("%lld\n",f[1]);
	return 0;
}