#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0,f=1; char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-')f=-1;
	 c=getchar();
}
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return f*ret;
}
int n,u,a[1500];
int main()
{
	n=read();
	for(int i=1; i<=n; ++i)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=n; i; --i)
	{
	    u=sqrt(a[i]+0.1);
	    if(u*u!=a[i])
	    {
	    	printf("%d\n",a[i]);  //_ ()  //puts() ""  "1"
	    	return 0;//exit 0
		}
	}
}