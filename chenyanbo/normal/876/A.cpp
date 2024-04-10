#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while (c>57 || c<48)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int n,a,b,c,ans;//m //_

int main()
{
	n=read();
	a=read();//_
	b=read();
	c=read();
	if(n==1)
	{
		puts("0");
		return 0;
		    
	}
	if(c<=a&&c<=b)
	{
		if(a<b)
		{
			ans=a;
		}
		else ans=b;
		ans+=(n-2)*c;//100 1000    ^2
		printf("%d\n",ans);//  %d\n  //wemku
		return 0;
	}
	printf("%d",(n-1)*min(a,b));
}