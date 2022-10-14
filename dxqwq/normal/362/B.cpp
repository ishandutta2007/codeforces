#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define QAQ int T=read(); while(T--)
using namespace std;
inline int read()
{
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll()
{
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[10003];
signed main()
{
    int n=read(),m=read();
    for(int i=1; i<=m; i++) a[i]=read();
    sort(a+1,a+m+1);
    if(a[1]==1 || a[m]==n) puts("NO"),exit(0);
    for(int i=1; i<m-1; i++) if(a[i]+1==a[i+1] && a[i+1]+1==a[i+2]) puts("NO"),exit(0);
    puts("YES");
    return 0;
}