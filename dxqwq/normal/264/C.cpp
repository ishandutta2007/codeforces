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
int a[100003],c[100003],tmp[100003],lst[100003];
long long ans[100003];
signed main()
{
    int n=read(),m=read();
    for(int i=1; i<=n; i++) a[i]=read();
    for(int i=1; i<=n; i++) c[i]=read(),lst[i]=tmp[c[i]],tmp[c[i]]=i;
    while(m--)
    {
        for(int i=1; i<=n; i++) ans[i]=0;
        int x=read(),y=read(),fir=0,t1=0,sec=0;
        swap(x,y);
        //not equal and equal
        for(int i=1; i<=n; i++) 
        {
            if(t1==c[i])
            {
                ans[i]=max(sec+x*a[i],fir+y*a[i]);
                if(lst[i]) ans[i]=max(ans[i],ans[lst[i]]);
                if(ans[i]>fir) fir=ans[i];
            }
            else 
            {
                ans[i]=fir+x*a[i];
                if(lst[i]) ans[i]=max(ans[i],ans[lst[i]]+y*a[i]),ans[i]=max(ans[i],ans[lst[i]]);
                if(ans[i]>fir) sec=fir,fir=ans[i],t1=c[i];
                else if(ans[i]>sec) sec=ans[i];     
                           
            }
        }
        long long Ans=0;
        for(int i=1; i<=n; i++) Ans=max(Ans,ans[i]);
        printf("%lld\n",Ans);
    }
    return 0;
}