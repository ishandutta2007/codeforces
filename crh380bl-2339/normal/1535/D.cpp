#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s[(1<<18)+2];
int id[(1<<18)+2],n;
int f[(1<<18)+2];
int y,p[(1<<18)+2];
void DFS(int x){
	if(x*2>n){
		if(s[p[x]]=='?')f[x]=2;
		else f[x]=1;
		return;
	}
	DFS(x+x);DFS(x+x+1);
	if(s[p[x]]=='0')f[x]=f[x+x];
	else if(s[p[x]]=='1')f[x]=f[x+x+1];
	else f[x]=f[x+x]+f[x+x+1];
	return;
}
char cc[3];
int dfs(int x){
	if(x>n)return 1;
	if(f[x])return f[x];
	int t1=dfs(x+x),t2=dfs(x+x+1);
	if(s[p[x]]=='0')return f[x]=t1;
	if(s[p[x]]=='1')return f[x]=t2;
	return f[x]=t1+t2;
}
int main(){
	int k,i,t,c,q,x;
	scanf("%d%s",&k,s+1);
	n=(1<<k)-1;
	for(i=1;i<=n;++i){
		t=n+1-i;c=0;
		while(t){
			t>>=1;
			++c;
		}
		t=n+1-i;
		id[i]=3*(1<<(c-1))-1-t;
	}
	for(i=1;i<=n;++i)p[id[i]]=i;
	DFS(1);
	scanf("%d",&q);
	while(q--){
		scanf("%d%s",&x,cc);
		s[x]=cc[0];
		x=id[x];y=x;
		while(x){
			f[x]=0;
			x>>=1;
		} 
		printf("%d\n",dfs(1));
	}
	return 0;
}