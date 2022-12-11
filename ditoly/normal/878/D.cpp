#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std; 
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define MK 12
bitset<1<<MK> b[MN+MK+5];
int a[MK+5][MN+5],p[MK+5],v;
bool cmp(int x,int y){return a[x][v]>a[y][v];}
int main()
{
	int n,k,q,i,j,s,cnt;
	n=read();cnt=k=read();q=read();
	for(i=1;i<=k;p[i]=i,++i)
	{
		for(j=1;j<=n;++j)a[i][j]=read();
		for(j=0;j<1<<k;++j)b[i][j]=bool(j&(1<<i-1)); 
	}
	while(q--)
	{
		i=read();j=read();v=read();
		if(i==1)b[++cnt]=b[j]|b[v];
		if(i==2)b[++cnt]=b[j]&b[v];
		if(i==3)
		{
			sort(p+1,p+k+1,cmp);
			for(i=1,s=0;;++i)if(b[j][s|=1<<p[i]-1])break;
			printf("%d\n",a[p[i]][v]);
		}
	}
}