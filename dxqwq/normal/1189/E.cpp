#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long a[1000003];
map<long long,int> mp;
int main()
{
    int n=read();
    long long p=read(),k=read();
    for(int i=1; i<=n; i++) a[i]=read(),++mp[(a[i]*a[i]%p*a[i]%p+p-k)*a[i]%p];
    long long ans=0;
    for(auto x:mp) ans+=1LL*x.second*(x.second-1);
    printf("%lld\n",ans/2);
	return 0;
}