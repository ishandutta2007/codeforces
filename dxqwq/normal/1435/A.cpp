#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[100003];
signed main()
{
    for(int T=read(); T--;) {
    int n=read();
    for(int i=1; i<=n; i++) a[i]=read();
    for(int i=1; i<=n; i+=2) swap(a[i],a[i+1]);
    for(int i=1; i<=n; i+=2) printf("%d %d ",a[i],-a[i+1]);
    puts("");
    }return 0;
}