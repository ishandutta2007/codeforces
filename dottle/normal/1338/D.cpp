#include<bits/stdc++.h>
const int N=1000050;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

int n,res,dg[N]; 
int f[N],g[N];

void dfs(int k,int fa){
	int xf=0,xg=0;
	fore(k)if(_to!=fa){
		dfs(_to,k);
		f[k]=max(f[k],g[_to]+dg[k]-2);
		g[k]=max(g[k],f[_to]+1);
		res=max({res,f[_to]+xf+1,g[_to]+xg+dg[k]-2});
		xf=max(xf,f[_to]);
		xg=max(xg,g[_to]);
	}
	f[k]=max(f[k],dg[k]-1);
	g[k]=max({f[k],g[k],1});
}

void solve(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		dg[x]++,dg[y]++;
		add(x,y);add(y,x);
	}
	dfs(1,0);
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	solve();
}