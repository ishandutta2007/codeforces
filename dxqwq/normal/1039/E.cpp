#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003],f[100003],mx[100003],mn[100003],ans[100003];
signed main()
{
    int n=read(),m=read(),q=read();
    for(int i=1; i<=n; ++i) a[i]=read();
    for(int i=1; i<=q; ++i) f[i]=m-read(),mx[i]=mn[i]=a[1];
    for(int i=2; i<=n; ++i) for(int j=1; j<=q; ++j) (mx[j]<a[i])&&(mx[j]=a[i]),(mn[j]>a[i])&&(mn[j]=a[i]),(mx[j]-mn[j]>f[j])&&(mx[j]=mn[j]=a[i],++ans[j]);
    for(int i=1; i<=q; ++i) printf("%d\n",ans[i]);
    return 0;
}