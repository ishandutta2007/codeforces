
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define L long long
#define D double
using namespace std;
int n,m,f[100010][25],h[100010],x[100010],y[100010],a[100010],b[200010],c[200010];
L s[100010],t[100010];
inline void dfs(int i)
{
	int j;
	for(j=1;j<=20;j++)
	  f[i][j]=f[f[i][j-1]][j-1];
	x[i]=1;
	for(j=a[i];j>0;j=c[j])
	  if(b[j]!=f[i][0])
	    {
	     f[b[j]][0]=i;
	     h[b[j]]=h[i]+1;
	     dfs(b[j]);
	     x[i]+=x[b[j]];
	     s[i]+=s[b[j]]+x[b[j]];
	    }
}
inline void dfs2(int i)
{
	int j;
	for(j=a[i];j>0;j=c[j])
	  if(b[j]!=f[i][0])
	    {
	     y[b[j]]=n-x[b[j]];
	     t[b[j]]=s[i]+t[i]-s[b[j]]-x[b[j]]+y[b[j]];
	     dfs2(b[j]);
	    }
}
inline int lca(int i,int j)
{
	int k;
	for(k=20;k>=0;k--)
	  if(h[j]-(1<<k)>=h[i])
	    j=f[j][k];
	if(i==j)
	  return i;
	for(k=20;k>=0;k--)
	  if(f[i][k]!=f[j][k])
	    {
	     i=f[i][k];
	     j=f[j][k];
	    }
	return f[i][0];
}
int main()
{
	int i,j,k,l;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	  {
	   scanf("%d%d",&j,&k);
	   b[2*i-1]=k;
	   c[2*i-1]=a[j];
	   a[j]=2*i-1;
	   b[2*i]=j;
	   c[2*i]=a[k];
	   a[k]=2*i;
      }
    dfs(1);
    dfs2(1);
    while(m--)
      {
       scanf("%d%d",&i,&j);
       if(h[i]>h[j])
         swap(i,j);
       k=lca(i,j);
       if(k==i)
         {
          for(k=j,l=20;l>=0;l--)
            if(h[k]-(1<<l)>h[i])
              k=f[k][l];
          printf("%.7f\n",h[j]-h[i]+1+(D)(s[i]-s[k]-x[k]+t[i])/(x[i]-x[k]+y[i])+(D)s[j]/x[j]);
         }
       else
         printf("%.7f\n",h[i]+h[j]-2*h[k]+1+(D)s[i]/x[i]+(D)s[j]/x[j]);
      }
	return 0;
}