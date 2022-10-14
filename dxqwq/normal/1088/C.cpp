#include<bits/stdc++.h>
using namespace std;
inline int read(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
long long a[2003];
int main()
{
    int n=read();
    long long Mx=0;
    for(int i=1; i<=n; i++) a[i]=read(),Mx=max(Mx,a[i]);
    ++Mx;
    Mx=max(1LL*n+3,Mx);
    printf("%d\n",n+1);
    for(int i=1; i<=n; i++) a[i]=Mx+i-1-a[i];
    a[n+1]=0;
    for(int i=1; i<=n; i++) printf("1 %d %lld\n",i,(a[i]-a[i+1]+Mx)%Mx);
    printf("2 %d %lld\n",n,Mx);
    return 0;
}