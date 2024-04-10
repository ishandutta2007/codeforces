#include<cstdio>
#include<iostream>
using namespace std;
const int o=210;
int T,n,p[o],q[o],fa[o];
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&p[fa[i]=i]),q[p[i]]=i;
		for(int i=1,u,v;i<=n;++i) if((u=fr(i))^(v=fr(p[i]))) fa[u]=v;
		for(int i=1,u,v;i<n;++i) if((u=fr(i))^(v=fr(i+1))) swap(p[q[i]],p[q[i+1]]),fa[u]=v;
		for(int i=q[n]=n-1;i;--i) q[i]=p[q[i+1]];
		for(int i=1;i<=n;++i) printf("%d ",q[i]);
	}
	return 0;
}