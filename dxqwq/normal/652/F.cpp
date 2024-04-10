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
int n=read(),m=read(),t=read(),cnt;
int x[1000003],ans[1000003];
struct node
{
    int pos,id,dir;
    bool operator<(const node& dreamerPaKIOI){return pos<dreamerPaKIOI.pos;};
}a[1000003];
signed main()
{
    char ch;
    for(int i=0; i<n; i++)
    {
        a[i].pos=read()-1,ch=getchar();
        while(!isupper(ch)) ch=getchar();
        a[i].dir=(ch=='R'),a[i].id=i;
    }
    sort(a,a+n);
    for(int i=0; i<n; i++) if(a[i].dir==1) cnt=(cnt+(a[i].pos+t)/m)%n,x[i]=(a[i].pos+t)%m; else cnt=(cnt+(a[i].pos-t)/m)%n,x[i]=(a[i].pos-t)%m,(x[i]<0)&&(x[i]+=m,cnt=(cnt+n-1)%n);
    cnt=(cnt+n)%n,sort(x,x+n);
    int tot=0;
    for(int i=cnt; i<n; i++) ans[a[tot++].id]=x[i];
    for(int i=0; i<cnt; i++) ans[a[tot++].id]=x[i];
    for(int i=0; i<n; i++) printf("%lld ",ans[i]+1);
    return 0;
}