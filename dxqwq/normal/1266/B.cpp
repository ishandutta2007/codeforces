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
char s[10003];
signed main()
{
    for(int T=read(); T--;)
    {
        int n=read();
        if(n<15)
        {
            puts("NO");
        }
        else
        {
            if(1<=n%14&&n%14<=6) puts("YES");
            else puts("NO");
        }
    }
	return 0;
}
//15~20; + 14