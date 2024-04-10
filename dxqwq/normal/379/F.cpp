#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int d[2000003],fa[2000003][23];
inline int dis(int x,int y)
{
    int res=d[x]+d[y];
    if(d[x]>d[y]) swap(x,y);
    for(int i=21; i>=0; --i) if(d[fa[y][i]]>=d[x]) y=fa[y][i];
    for(int i=21; i>=0; --i) if(fa[y][i]^fa[x][i]) x=fa[x][i],y=fa[y][i];
    x=fa[x][0];
    return res-2*d[x];
}
signed main()
{
	int n=read(),cnt=4;
    int p=2,q=3,r=2;
    fa[2][0]=fa[3][0]=fa[4][0]=d[2]=d[3]=d[4]=1;
    while(n--)
    {
        int x=read();
        fa[++cnt][0]=x,d[cnt]=d[x]+1;
        for(int i=1; i<=21; ++i) fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
        if(dis(cnt,p)>r) r=dis(cnt,p),q=cnt;
        else if(dis(cnt,q)>r) r=dis(cnt,q),p=cnt;
        fa[++cnt][0]=x,d[cnt]=d[x]+1;
        for(int i=1; i<=21; ++i) fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
        if(dis(cnt,p)>r) r=dis(cnt,p),q=cnt;
        else if(dis(cnt,q)>r) r=dis(cnt,q),p=cnt;
        printf("%d\n",r);
    }
    return 0;
}