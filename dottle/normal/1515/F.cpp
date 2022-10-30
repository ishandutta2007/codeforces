#include<bits/stdc++.h>
#define _to e[i].to
#define int long long 
const int N=1000000; 
using namespace std; 
struct edge{
	int nx,to,id;
}e[N];int hd[N],S;
void add(int fr,int to,int id){
	e[++S]=(edge){hd[fr],to,id},hd[fr]=S;
}
int n,m,x,a[N],s,l=1,r,ans[N],f,t,v[N];

void dfs(int k){
	v[k]=1;
	for(int i=hd[k];i;i=e[i].nx)
		if(!v[_to]){
			dfs(_to);
			if(a[k]+a[_to]>x)a[k]+=a[_to]-x,ans[l++]=e[i].id;
			else ans[r--]=e[i].id;
		}
}

main(){
	scanf("%d%d%d",&n,&m,&x),r=n-1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s+=a[i];
	if(s<x*(n-1))printf("NO"),exit(0);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&f,&t),add(f,t,i),add(t,f,i);
	dfs(1);
	printf("YES\n");
	for(int i=1;i<n;i++)printf("%d\n",ans[i]);
}