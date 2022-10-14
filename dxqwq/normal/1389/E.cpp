#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long gcd(long long p,long long q)
{
	if(p>q) swap(p,q);
	while(p)
	{
		q%=p,swap(p,q);
	}
	return q;
}
int main()
{
	int T=read();
	while(T--)
	{
		long long x=read(),y=read(),z=read(),w=z/gcd(z,y-1);
		long long tmp=(min(x,y)-1)/w;
		long long ans=tmp*min(x,y)-tmp*(tmp+1)/2*w;
		//for(long long t=1; t*w<min(x,y); t++) ans+=min(x,y)-(t*w);
		printf("%lld\n",ans);		
	}//w|(x-y)
 
    return 0;
}//asdfkjhgasdfkjhdsfkjhsgdfkjhdsafkjhdsafkjdsfkjdfs