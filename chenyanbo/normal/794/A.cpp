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
int a,b,c,n;
int main()  
{
	int ans=0; //=0
	scanf("%d%d%d",&a,&b,&c);
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		int g=read();
		if(g>b && g<c)++ans;  //max
	}
	printf("%d\n",ans); //\n  \r\n
}