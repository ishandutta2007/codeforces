#include <bits/stdc++.h>
using namespace std;
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
	puts("NO");
	exit(0);
}
int n,root;
vector<int>g[5004];
int a[5003],sub[5003],num[5003];
void dfs1(int x,int cnt){
	num[x]+=cnt;
	for (int i=0;i<g[x].size();i++) dfs1(g[x][i],cnt);
}
void dfs2(int x,int cnt){
	if (num[x]>=cnt) num[x]++;
	for (int i=0;i<g[x].size();i++) dfs2(g[x][i],cnt);
}
void dfs(int x){
	for (int i=0;i<g[x].size();i++) dfs(g[x][i]),sub[x]+=sub[g[x][i]];
	if (a[x]>sub[x]) outputno();
	sub[x]++;
	if (g[x].empty()){
		num[x]=1;
		return;
	}
	int cnt=0;
	for (int i=0;i<g[x].size();i++)dfs1(g[x][i],cnt),cnt+=sub[g[x][i]];
	num[x]=a[x]+1;
	for (int i=0;i<g[x].size();i++)dfs2(g[x][i],a[x]+1);
}
int main(){
	read(n);
	for (int i=1;i<=n;i++){
		int x;read(x),read(a[i]);
		if (x==0) root=i;
		else g[x].push_back(i); 
	}
	dfs(root);
	puts("YES");
	for (int i=1;i<=n;i++) write(num[i]),putchar(' ');
}