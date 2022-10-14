// Problem: CF258D Little Elephant and Broken Sorting
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF258D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[3003],b[3003],x[3003];
double f[3003][3003];
signed main()
{
    int n=read(),m=read();
    for(int i=1; i<=n; i++) x[i]=read();
    for(int i=1; i<=m; i++) a[i]=read(),b[i]=read();
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(x[i]>x[j]) f[i][j]=1;
    for(int i=1; i<=m; i++)
    {
        f[a[i]][b[i]]=f[b[i]][a[i]]=(f[a[i]][b[i]]+f[b[i]][a[i]])*0.5;
        for(int j=1; j<=n; j++)
        {
            if(j==a[i] || j==b[i]) continue;
            f[a[i]][j]=f[b[i]][j]=(f[a[i]][j]+f[b[i]][j])*0.5;
            f[j][a[i]]=f[j][b[i]]=(f[j][a[i]]+f[j][b[i]])*0.5;
        }
    }
    double ans=0;
    for(int i=1; i<n; i++) for(int j=i+1; j<=n; j++) ans+=f[i][j];
    printf("%.10lf\n",ans);
    return 0;
}