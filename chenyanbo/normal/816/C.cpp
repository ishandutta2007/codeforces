#include<cstdio>
#include<iostream>
#include<climits>
#include<vector>
#include<set> 
#include<algorithm>
#define N 150
int h2[60000],h1[60000],t1,t2,k,ans,mi[N],mi2[N],fl,a[N][N],n,m;
using namespace std;
inline int read()
{
	unsigned ret=0; char c=getchar();
	while(c>57 || c<48) c=getchar();
	while(c>=48&&c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int main()
{
	n=read(); m=read(); //scanf  &
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=m; ++j)a[i][j]=read();
	while(1)
	{
		fl=false;
		
		
		//
		for(int i=1; i<=n; ++i)
		{
			mi[i]=500;
			for(int j=1; j<=m; ++j)mi[i]=min(mi[i],a[i][j]);
		}
		for(int i=1; i<=m; ++i)
		{
			mi2[i]=500;
			for(int j=1; j<=n; ++j)mi2[i]=min(mi2[i],a[j][i]);
		}
		//
		
		
		for(int i=1; i<=n; ++i)   
		{
			for(int j=1; j<=m; ++j)if(a[i][j]>mi[i])
			{                 //j
				for(int j_=1; j_<=n; ++j_)if(a[j_][j])--a[j_][j];else {
					printf("-1");
					return 0; ///exit(0) 
				}
				h2[++t2]=j;
				++ans;
				fl=true;
				break;
			} 
			if(fl)break;
		}
		if(fl)continue;
		for(int i=1; i<=m; ++i)
		{
			for(int j=1; j<=n; ++j)if(a[j][i]>mi2[i])
			{
				for(int j_=1; j_<=m; ++j_)if(a[j][j_])--a[j][j_];else {
					printf("-1");
					return 0; ///exit(0) 
				}
				fl=true;
				h1[++t1]=j;
				++ans;
				break;
			} 
			if(fl)break;
		}
		if(!fl)break;
	}
	k=a[1][1];
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=m; ++j)if(a[i][j]!=k)
	{
					printf("-1");
					return 0; ///exit(0) 
				}
	ans+=k*min(n,m);
	printf("%d\n",ans);
	for(int i=1; i<=t1; ++i)printf("row %d\n",h1[i]);
	for(int i=1; i<=t2; ++i)printf("col %d\n",h2[i]);
	for(int i=1; i<=k; ++i)
	{
		if(n<m)
		for(int i=1; i<=n; ++i)printf("row %d\n",i);
		else for(int i=1; i<=m; ++i)printf("col %d\n",i);
	}
}