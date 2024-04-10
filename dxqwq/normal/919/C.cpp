#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char a[2003][2003];
int main()
{
    int n=read(),m=read(),k=read(),ans=0;
    for(int i=1; i<=n; i++) scanf("%s",a[i]+1);
    for(int i=1; i<=n; i++) 
    {
        int lst=0;
        for(int j=1; j<=m; j++) if(a[i][j]=='*') lst=j; else if(j-lst>=k) ++ans;
    }
    for(int i=1; i<=m; i++) 
    {
        int lst=0;
        for(int j=1; j<=n; j++) if(a[j][i]=='*') lst=j; else if(j-lst>=k) ++ans;
    }
    if(k==1) ans>>=1;
    cout<<ans;
    return 0;
}