#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define mkp make_pair
#define fi first
#define se second 
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void outputno(){
	puts("-1");exit(0);
}
int n,m; 
int par[5003],depth[5003],fr[5003],ans[5003];
vector<int>g[5003],num[5003];
vector<piii>v;
void dfs(int x,int parts,int dep){
	par[x]=parts,depth[x]=dep;
	for (int i=0;i<g[x].size();i++) if (g[x][i]!=parts)
		dfs(g[x][i],x,dep+1),fr[g[x][i]]=num[x][i];
}
int main(){
	read(n);
	for (int i=1;i<n;i++){
		int x,y;read(x),read(y),g[x].push_back(y),g[y].push_back(x),num[x].push_back(i),num[y].push_back(i); 
	}
	dfs(1,-1,0);
	read(m); 
	for (int i=0;i<m;i++){
		int a,b,c;read(a),read(b),read(c);
		v.push_back(mkp(c,mkp(a,b)));
	}
	for (int i=1;i<n;i++) ans[i]=1;
	sort (v.begin(),v.end());
	for (int i=0;i<m;i++){
		int a=v[i].se.fi,b=v[i].se.se,x=v[i].fi;
		if (depth[a]>depth[b]) swap(a,b);
		while (depth[b]>depth[a])
			ans[fr[b]]=x,b=par[b];
		while (par[b]!=par[a]) ans[fr[b]]=ans[fr[a]]=x,a=par[a],b=par[b];
		if (a!=b)ans[fr[a]]=ans[fr[b]]=x;
	}
	for (int i=0;i<m;i++){
		int a=v[i].se.fi,b=v[i].se.se,x=v[i].fi,res=1e6;
		if (depth[a]>depth[b]) swap(a,b);
		while (depth[b]>depth[a])
			res=min(res,ans[fr[b]]),b=par[b];
		while (par[b]!=par[a]) res=min(res,ans[fr[a]]),res=min(res,ans[fr[b]]),a=par[a],b=par[b];
		if (a!=b) res=min(res,ans[fr[a]]),res=min(res,ans[fr[b]]);
		if (res!=x) outputno();
	}
	for (int i=1;i<n;i++) write(ans[i]),putchar(' ');
}