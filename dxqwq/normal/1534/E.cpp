// Problem: CF1534E Lost Array
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1534E
// Memory Limit: 250 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int cnt[1000003];
int a[1000003],c;
int f[1003][1003];
int main()
{
    int n=read(),k=read();
    if(!(k&1)&&(n&1)) puts("-1"),exit(0);
    int S=1,T;
    while(1)
    {
        while(((S*k)&1)^(n&1)) ++S;
        T=S;
        if(!(T&1)) --T;
        int mn=n,mx=n*T;
        if(mn>S*k||mx<S*k) ++S;
        else break;
    }
    int sum=S*k-n;
    for(int i=1; i<=n; ++i) cnt[i]=1;
    for(int i=1; i<=n; ++i) while(cnt[i]+2<=T&&sum) cnt[i]+=2,sum-=2;
    for(int i=1; i<=n; ++i) for(int j=1; j<=cnt[i]; j++) a[++c]=i;
    for(int i=1; i<=c; ++i) f[(i-1)%S][(i-1)/S]=a[i];
    int ans=0;
    for(int i=0; i<S; ++i)
    {
        printf("? ");
        for(int j=0; j<k; ++j) printf("%d ",f[i][j]);
        puts("");fflush(stdout);
        ans^=read();
    }
	printf("! %d\n",ans);
	return 0;
}