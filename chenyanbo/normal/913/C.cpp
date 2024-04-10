#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

long long ans;
//int 
long long n,L,ll,LL,lL,Ll;
long long c[60],ma,mi; 
int main()
{
	n=read(); L=read();
	for(int i=1; i<=n; ++i)c[i]=read();
	for(int i=1; i<=n; ++i)if(c[i]<<1 <c[i+1])c[i+1]=c[i]<<1;
//	for(int )
    mi=c[n]; ma=1ll<<62;  //ll  ull //   double=1e62	
    ans=L/(1<<(n-1))*c[n];
    L%=(1<<(n-1));  //no %= ()%=  //()   ll -4  //()
	for(int i=n; i>=1; --i)
	{ 
		c[i]=min(c[i],mi);
		mi=min(c[i],mi);
		if(1<<(i-1)<=L)
		{
			L-=1<<(i-1);
			ans+=c[i];
		}
		else ma=min(ma,ans+c[i]);
	}
	ma=min(ma,ans);
	printf("%I64d\n",ma);   //lld
}