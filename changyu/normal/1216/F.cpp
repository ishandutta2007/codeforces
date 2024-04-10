#include<cstdio>
namespace io{
const int D=1<<20;char buf[D],*s,*t;
inline char get(){return s==t&&(t=(s=buf)+fread(buf,1,D,stdin),s==t)?-1:*s++;}
inline char readchar(){
    char c=get();
    for(;c!=48&&c!=49;c=get());
    return c;
}
inline int read(){
    int a=0;char c=get();
    for(;c<48||c>57;c=get());for(;c>47&&c<58;a=a*10+c-48,c=get());
    return a;
}
}
using io::readchar;
using io::read;
#define min(a,b)((a)<(b)?(a):(b))
#define max(a,b)((a)>(b)?(a):(b))
const int N=5e6+3;
int q[N],l,r,n,m;long long dp[N];char a[N];
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=readchar();
    q[l=r=0]=0;
    for(int i=1;i<=n;i++){
      dp[i]=dp[i-1]+i;
      for(;l<=r&&q[l]<i-m-m-1;l++);
      if(l<=r&&i-m>0&&a[i-m]=='1')dp[i]=min(dp[i],dp[q[l]]+i-m);
      for(;l<=r&&dp[i]<=dp[q[r]];r--);
      q[++r]=i;
    }
    for(int i=max(n-m+1,1);i<=n;i++){
      for(;l<=r&&q[l]<i-m-1;l++);
      if(l<=r&&a[i]=='1')dp[n]=min(dp[n],dp[q[l]]+i);
    }
    printf("%lld\n",dp[n]);
    return 0;
}