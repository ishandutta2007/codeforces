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
int n,m,a[1000],b[1000],h,g;
int main()
{
	n=read(),m=read();
	for(int i=1; i<=n; ++i)a[i]=read();
	for(int i=1; i<=m; ++i)b[i]=read(); //
	for(int i=1; i<=n; ++i)if(!a[i])++h;
	if(h>1)
	{
		puts("Yes");
		exit(0);//return 0
	}
	g=1;
	for(int i=2; i<=n; ++i)if(a[i])
	{
		if(a[i]<a[i-1])
		{
			puts("Yes");
			exit(0);
		}
	}else g=i;
	if(g==1 && a[1])
	{
		puts("No");
		return 0;
	}
	sort(b+1,b+m+1);
	if(g==1)
	{//>=  //yange?    shangsheng    bujiang
		if(b[m]>a[2])
		{
			puts("Yes");
			exit(0);
		}
	}
	else
	{
		if(g==n)
		{
			if(b[1]<a[n-1])
		    { 
			    puts("Yes");
			    exit(0);
	    	}
		}
		else
		{
			if(b[1]<a[g-1]  ||  b[m]>a[g+1])
		    { 
			    puts("Yes");
			    exit(0);
	    	}
		}
	}
			    puts("No");
}