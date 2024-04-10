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

signed main()
{
    int a=read(),b=read();
    if(a==0 && b==0) puts("NO");
    else if(a==b) puts("YES");
    else if(a+1==b) puts("YES");
    else if(a==b+1) puts("YES");
    else puts("NO");
    return 0;
}