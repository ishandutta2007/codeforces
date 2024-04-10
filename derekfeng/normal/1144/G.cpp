#include<bits/stdc++.h>
using namespace std;
int n,a[200004];
int f[200004],g[200004];
bool ff[200004],gg[200004];
void dfs(int x,bool t){
	if(t){
		if(x>1){
			if(ff[x-1]&&a[x-1]<a[x]&&f[x]==f[x-1])dfs(x-1,1);
			else dfs(x-1,0);
		}
		putchar('0'),putchar(' ');
	}else{
		if(x>1){
			if(ff[x-1]&&f[x-1]>a[x]&&g[x]==a[x-1])dfs(x-1,1);
			else dfs(x-1,0);
		}
		putchar('1'),putchar(' ');
	}
}
int main(){
	scanf("%d%d",&n,&a[1]);
	f[1]=1e9,g[1]=-1;
	ff[1]=gg[1]=1;
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		g[i]=1e9,f[i]=-1;
		if(ff[i-1]){
			if(a[i-1]<a[i])f[i]=max(f[i],f[i-1]),ff[i]=1;
			if(f[i-1]>a[i])g[i]=min(g[i],a[i-1]),gg[i]=1;
		}
		if(gg[i-1]){
			if(g[i-1]<a[i])f[i]=max(f[i],a[i-1]),ff[i]=1;
			if(a[i-1]>a[i])g[i]=min(g[i],g[i-1]),gg[i]=1;
		}
		if(!ff[i]&&!gg[i])return puts("NO"),0;
	}
	puts("YES");
	dfs(n,ff[n]);
}