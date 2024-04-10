#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=200005;
int h[N],q[N],dp[N],in[N],f[N],vis[N];
int n,m,l,r,u,v,p;
vi e[N];

int main(){
	read(n),read(m),p=n;
	rep(i,1,n) read(h[i]);
	rep(i,1,m) read(u),read(v),e[u].pb(v),in[v]++;
	rep(i,1,n) if(!in[i]) q[r++]=i;
	for(int u=q[l++];l<=r;u=q[l++])
		for(auto v:e[u]) if(!(--in[v])) q[r++]=v;
	per(i,n-1,0){
		int u=q[i];
		for(auto v:e[u]) vis[dp[v]]=1;
		while(vis[dp[u]]) dp[u]++;
		for(auto v:e[u]) vis[dp[v]]=0;
		f[dp[u]]^=h[u];
	}
	while(p>=0&&!f[p]) p--;
	if(p==-1) return puts("LOSE"),0;
	rep(u,1,n) if(dp[u]==p&&(h[u]^f[p])<h[u]){
		h[u]^=f[p],f[p]=0;
		for(auto v:e[u]) h[v]^=f[dp[v]],f[dp[v]]=0;
	}
	puts("WIN");
	rep(i,1,n) printf("%d ",h[i]);
	return 0;
}