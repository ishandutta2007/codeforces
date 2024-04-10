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
        int n=read();
        if(n<=30) puts("NO");
        else
        {
        	puts("YES");
            if(n==36) puts("5 6 10 15"); else if(n==40) puts("9 6 10 15"); else if(n==44) puts("6 7 10 21"); else printf("6 10 14 %d\n",n-30);
        }
    }
    return 0;
}