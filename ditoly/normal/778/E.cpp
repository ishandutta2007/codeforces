#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MN 1001
char a[MN+5],b[MN+5][MN+5],s[MN+5];
int l[MN+5],f[MN+5][MN+5],g[MN+5][MN+5],sa[MN+5][MN+5],c[MN+5],ss[10];
void read(char*a,int p)
{
	scanf("%s",s);
	while(s[l[p]])++l[p];
	for(int i=0;s[i];++i)a[l[p]-i]=s[i];
}
int get(int x,int y){return b[x][y]?b[x][y]-'0':0;}
int value(int x,int y){return y>max(l[x],l[0])&&!g[x][y]?0:c[g[x][y]];}
int main()
{
	int n,i,j,k,r,p,v;
	read(a,0);scanf("%d",&n);
	for(i=1;i<=n;++i)read(b[i],i);
	for(i=0;i<10;++i)scanf("%d",&c[i]);
	for(i=1;i<=n;++i)sa[0][i]=i;
	memset(f,128,sizeof(f));f[0][0]=0;
	for(i=1;i<=MN;++i)
	{
		memset(ss,0,sizeof(ss));
		for(j=1;j<=n;++j)++ss[get(j,i)];
		for(j=9;j;--j)ss[j-1]+=ss[j];
		for(j=n;j;--j)sa[i][ss[get(sa[i-1][j],i)]--]=sa[i-1][j];
		if(i>l[0])j=r=0;
		else if(a[i]=='?')j=i==l[0],r=9;
		else j=r=a[i]-'0';
		for(;j<=r;++j)
		{
			for(p=v=0,k=1;k<=n;++k)
			{
				g[k][i]=get(k,i)+j;
				if(g[k][i]>9)g[k][i]-=10,++p;
				v+=value(k,i); 
			}
			for(k=0;;)
			{
				f[i][p]=max(f[i][p],f[i-1][k]+v);
				if(k++==n)break;
				v-=value(sa[i-1][k],i);
				if(++g[sa[i-1][k]][i]>9)g[sa[i-1][k]][i]=0,++p;
				v+=value(sa[i-1][k],i);
			}
		}
	}
	printf("%d",f[MN][0]);
}