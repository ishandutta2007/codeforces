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

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int mod=1e9+7;
const int N=100005;
struct node{
	ll v;int c;
};
ll x[N],ans;
int n,a,b;
vi e[N];

void dfs(int u,int fa,vector<node> vec){
	vector<node> nw;
	vec.pb((node){0,1});
	for(auto t:vec){
		ll now=__gcd(x[u],t.v);
		if(!nw.empty()&&nw.back().v==now)
			nw[nw.size()-1].c+=t.c;
		else
			nw.pb((node){now,t.c});
		//printf("# %d  %lld  %d\n",u,now,t.c);
		ans=(ans+now%mod*t.c)%mod;
	}
	for(auto v:e[u])
		if(v!=fa)dfs(v,u,nw);
}

int main(){
	read(n);
	rep(i,1,n)read(x[i]);
	rep(i,1,n-1){
		read(a),read(b);
		e[a].pb(b);
		e[b].pb(a);
	}
	vector<node> vec;
	dfs(1,0,vec);
	cout<<((ans+mod)%mod)<<endl;
	return 0;
}