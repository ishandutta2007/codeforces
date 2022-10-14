#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[100003],b[100003];
signed main()
{
    int n=read(),m=read();
    for(int i=1; i<=n; i++) a[i]=read();
    for(int i=1; i<=n; i++) b[i]=read();
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++) b[j]=(b[j]+1)%m;
        sort(b+1,b+n+1);
        bool f=1;
        for(int j=1; j<=n; j++) if(a[j]!=b[j]) f=0;
        if(f) puts("YES"),exit(0);
    }
    puts("NO"),exit(0);
    return 0;
}