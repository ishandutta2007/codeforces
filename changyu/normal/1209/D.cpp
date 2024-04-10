#include<cstdio>
const int N=1e5+3;
int n,m,p[N],ans;
int Find(int k){return p[k]==k?k:p[k]=Find(p[k]);}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(u=1;u<=n;u++)p[u]=u;
	for(;m--;)scanf("%d%d",&u,&v),Find(u)==Find(v)?ans++:p[Find(u)]=Find(v);
	return 0*printf("%d",ans);
}