#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int main()
{
	int T=read();
    while(T--)
    {
        int n=read(),m=n-((n-1)/4+1);
        for(int i=1; i<=m; i++) putchar('9');
        for(int i=1; i<=n-m; i++) putchar('8');
        puts("");
    }
    return 0;
}