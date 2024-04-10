#include<bits/stdc++.h>
#define N 210007
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int ss,v,n,p,f,s,h;
int a[N],b[N],ans;  //long long //1 1ll
int main()
{
	n=read();
	for(int i=1; i<=n; ++i)a[i]=read();
	for(int i=n+1; i<=n+n; ++i)a[i]=a[i-n];
	s=read(); f=read(); 
	h=f-s;
	for(int i=1; i<=n+n; ++i)b[i]=b[i-1]+a[i];
	 
	for(int i=1; i<=n; ++i)
	{ 
		if(b[i+h-1]-b[i-1]>ans)
		{
		    ans=b[i+h-1]-b[i-1],p=i,ss=(s+(n+1-p))%n; 
	        if(!ss)ss=n;
	    }
	    else if(b[i+h-1]-b[i-1]==ans)
	    {
	    	v=(s+(n+1-i))%n;
	    	if(!v)v=n;
	    	ss=min(ss,v);
		}
	}
	printf("%d\n",ss);
}