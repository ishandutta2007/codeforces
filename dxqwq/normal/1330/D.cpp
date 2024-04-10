#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int main()
{
	int t=read();
	while(t--)
	{
		long long n,m,ans=1;
		scanf("%lld%lld",&n,&m);
		for(long long k=1; k<=n; k<<=1) ans*=min((k<<1)-1,n)-k+2,ans%=m;
		printf("%lld\n",(ans+m-1)%m);
	}
	return 0;
}