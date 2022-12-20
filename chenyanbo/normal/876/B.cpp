#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while (c>57 || c<48)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int n,m,k,a[300101],p[300010];
int main()
{
	n=read(); k=read(); m=read();
	for(int i=1; i<=n; ++i)
	{
		a[i]=read();
		++p[a[i]%m];
	}//fre  fre        frefre
	for(int i=0; i<m; ++i)if(p[i]>=k)
	{
		puts("Yes");
		int ii=0;//=0
		for(int j=1; j<=n; ++j)
		{
			
			if(a[j]%m==i)
			{//  //
				printf("%d ",a[j]);
				++ii;
				if(ii==k)return 0;
			}
		}
//		return 0;//exit(0)
	}
	printf("No");
}