#include<bits/stdc++.h>
const int N=2e5+3;
int n,m,x[N],y[N],z[N],p[N],s[N],ans;
int Find(int k){
	if(p[k]==k)return k;
	int r=Find(p[k]);
	s[k]^=s[p[k]];
	return p[k]=r;
}
inline void Merge(int u,int v,int c){
	int uu=Find(u),vv=Find(v);
	if(uu==vv){
		if(s[u]^s[v]^c)ans=0;
	}
	else p[uu]=vv,s[uu]=s[u]^s[v]^c;
}
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d",&n,&m);
	for(int u=1;u<=n;u++)p[u]=u,s[u]=0;
	ans=1;
	for(int i=1,u,v,c;i<n;i++){
		scanf("%d%d%d",&u,&v,&c);
		x[i]=u,y[i]=v,z[i]=c;
		if(~c)Merge(u,v,__builtin_popcount(c)&1);
	}
	for(int u,v,c;m--;){
		scanf("%d%d%d",&u,&v,&c);
		Merge(u,v,c);
	}
	if(!ans){puts("NO");continue;}
	puts("YES");
	for(int i=1,u,v,c;i<n;i++){
		u=x[i],v=y[i],c=z[i];
		if(~c){printf("%d %d %d\n",u,v,c);continue;}
		if(Find(u)==Find(v)){printf("%d %d %d\n",u,v,s[u]^s[v]);continue;}
		printf("%d %d %d\n",u,v,0);
		Merge(u,v,0);
	}
	}return 0;
}