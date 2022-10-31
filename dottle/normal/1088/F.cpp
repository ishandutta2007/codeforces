#include<bits/stdc++.h>
#define int long long
const int N=1005000,P=20;
using namespace std;

int rt,n,a[N],f[P][N],ans;
#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S;
}

void dfs(int k,int fa){
	f[0][k]=fa;
	int na=a[fa]+a[k];
	for(int i=1;i<P;i++){
		f[i][k]=f[i-1][f[i-1][k]];
		if(f[i][k])na=min(na,a[f[i][k]]+a[k]+i*a[f[i][k]]);
	}
	ans+=na;
	fore(k)if(_to!=fa)dfs(_to,k);
}

main(){
	ios::sync_with_stdio(0);
	cin>>n;rt=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[rt])rt=i;
	}
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(rt,rt);
	cout<<ans-a[rt]*2<<endl;
}