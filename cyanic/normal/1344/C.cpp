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

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=200005;
int in[N],q[N],f[N],g[N],ans,n,m,x,y,l,r;
vi e[N],re[N];

int main(){
	read(n),read(m);
	rep(i,1,m){
		read(x),read(y);
		e[x].pb(y),re[y].pb(x),in[y]++;
	}
	rep(i,1,n){
		if(!in[i]) q[r++]=i;
	}
	while(l<r){
		int u=q[l++];
		for(auto v:e[u]) if(!(--in[v])) q[r++]=v;
	}
	if(r<n){
		puts("-1");
		return 0;
	}
	rep(i,0,n-1){
		int u=q[i];
		f[u]=u;
		for(auto v:re[u]) 
			f[u]=min(f[u],f[v]);
	}
	per(i,n-1,0){
		int u=q[i];
		g[u]=u;
		for(auto v:e[u])
			g[u]=min(g[u],g[v]);
	}
	rep(u,1,n){
		ans+=(f[u]==u&&g[u]==u);
	}
	cout<<ans<<endl;
	rep(u,1,n){
		putchar(f[u]==u&&g[u]==u?'A':'E');
	}
	return 0;
}