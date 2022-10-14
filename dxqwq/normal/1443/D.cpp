//zhouAKngyang AK IOI!
#include<bits/stdc++.h>
using namespace std; 
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int main()
{
    for(int T=read(); T--;)
    {
        int n=read();
        for(int i=1; i<=n; i++) a[i]=read();
        int x=1000000000;
        for(int i=1; i<=n; i++) 
        {
            x=min(x,a[i]-a[i-1]);
            x=max(x,0);
            a[i]-=x;
        }
        x=1000000000;
        for(int i=n; i>=1; i--) x=min(x,a[i]),a[i]-=x;
        bool f=1;
        for(int i=1; i<=n; i++) if(a[i]) f=0;
        if(f) puts("YES"); else puts("NO");
    }
	return 0;
}