#include<bits/stdc++.h>
#define int long long
using namespace std; 
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int f(int x)
{
    if((x&3)==0) return x;
    if((x&3)==1) return 1;
    if((x&3)==2) return x^1;
    if((x&3)==3) return 0;
}
signed main()
{
    int n=read(),ans=0;
    for(int i=1; i<=n; i++)
    {
        int x=read(),y=read();
        ans^=f(x+y-1),ans^=f(x-1);
    }
    if(ans) puts("tolik"); else puts("bolik");
	return 0;
}