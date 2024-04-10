#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,a[100004],num[100004],now[100004][2];
vector<int>g[100004];
ll ans,d;
void dfs(int x,int par){
	for (int j=0;j<2;j++) now[x][j]=0;
	d+=num[x],now[x][num[x]]++;
	for (int i=0;i<g[x].size();i++) if (g[x][i]!=par){
		dfs(g[x][i],x);
		for (int j=0;j<2;j++) d+=1ll*now[x][j]*now[g[x][i]][j^1];
		for (int j=0;j<2;j++) now[x][j^num[x]]+=now[g[x][i]][j];
	}
}
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<n;i++){
		int x,y;read(x),read(y),g[x].push_back(y),g[y].push_back(x); 
	}
	for (int i=0;i<20;i++){
		d=0;
		for (int j=1;j<=n;j++) num[j]=((a[j]>>i)&1);
		dfs(1,-1);
		ans+=d*(1<<i);
	}
	write(ans);
}