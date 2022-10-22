#include<cstdio>
int a,b;
int G(int a,int b){return b?G(b,a%b):a;}
signed main()
{
	int T;scanf("%d",&T);for(;T--;)scanf("%d%d",&a,&b),puts(G(a,b)>1?"Infinite":"Finite");
	return 0;
}