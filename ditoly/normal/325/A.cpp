#include<cstdio>
#include<algorithm>
using namespace std; 
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
int xl[5],xr[5],yl[5],yr[5],cx[10],cxn,cy[10],cyn,u[10][10];
int main()
{
	int n=read(),i,j,k;
	for(i=0;i<n;++i)
	{
		cx[cxn++]=xl[i]=read();
		cy[cyn++]=yl[i]=read();
		cx[cxn++]=xr[i]=read();
		cy[cyn++]=yr[i]=read();
	}
	sort(cx,cx+cxn);cxn=unique(cx,cx+cxn)-cx;
	sort(cy,cy+cyn);cyn=unique(cy,cy+cyn)-cy;
	for(i=0;i<n;++i)for(j=1;j<cxn;++j)for(k=1;k<cyn;++k)
		u[j][k]|=xl[i]<=cx[j-1]&&cx[j]<=xr[i]&&yl[i]<=cy[k-1]&&cy[k]<=yr[i];
	for(i=1;i<cxn;++i)for(j=1;j<cyn;++j)if(!u[i][j])return 0*puts("NO");
	puts(cx[cxn-1]-cx[0]==cy[cyn-1]-cy[0]?"YES":"NO");
}