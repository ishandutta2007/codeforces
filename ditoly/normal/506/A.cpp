#include<cstdio>
#include<cstring>
#define MN 30000
#define MX 250
int a[MN+5],f[MN+5][MX*2+5];
inline void rw(int&a,int b){if(b>a)a=b;}
inline int&F(int x,int y){return f[x][MX+y];}
int main()
{
	int n,d,i,j,ans=0;
	scanf("%d%d",&n,&d);
	while(n--)scanf("%d",&i),++a[i];
	memset(f,200,sizeof(f));
	for(F(i=d,0)=0;i<=MN;++i)for(j=-MX;j<=MX;++j)if(F(i,j)>=0)
	{
		rw(ans,F(i,j)+=a[i]);
		if(i+d+j+1<=MN)rw(F(i+d+j+1,j+1),F(i,j));
		if(i+d+j<=MN)rw(F(i+d+j,j),F(i,j));
		if(d+j>1&&i+d+j-1<=MN)rw(F(i+d+j-1,j-1),F(i,j));
	}
	printf("%d",ans);
}