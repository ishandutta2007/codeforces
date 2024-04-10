#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=210,INF=1e9;
int n,k,w[MAXN],u,v,ans;
vector<int>e[MAXN];
struct State{
	deque<int>data;
	int sz;
	void resize(int sz){
		this->sz=sz;
		data.resize(sz+1);
	}
	void extend(){
		sz++;
		data.insert(data.begin(),data.front());
	}
}f[MAXN];
void Merge(State& parent,State& child){
	if(parent.sz<child.sz)swap(parent,child);
	//childparent
	deque<int>tmp=child.data;
	rep(j,0,child.sz){
		int lim=Max(k-j+1,j);
		if(lim<=child.sz)tmp[j]=Max(tmp[j],parent.data[j]+child.data[lim]);
		if(lim<=parent.sz)tmp[j]=Max(tmp[j],parent.data[lim]+child.data[j]);
	}
	int suf=0;
	per(j,child.sz,0){
		suf=Max(suf,tmp[j]);
		parent.data[j]=Max(parent.data[j],suf);
	}
}
void dp(int u,int fa){
	f[u].resize(1);
	f[u].data[0]=w[u];
	for(vit it=e[u].begin();it!=e[u].end();it++){
		int v=*it;if(v==fa)continue;
		dp(v,u);
		f[v].extend();
		Merge(f[u],f[v]);
	} 
}
int main(){
	cin>>n>>k;
	rep(i,1,n)cin>>w[i];
	rep(i,1,n-1){
		cin>>u>>v;
		e[u].pb(v);e[v].pb(u);
	}
	dp(1,0);
	cout<<f[1].data[0];
	return 0;
}