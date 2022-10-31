#include <cstdio>
#include <iostream>
#include <cstring>
#define ull unsigned long long
using namespace std;
const int N=5e5; 
const int sz=19;
const int base=130000001ull;
char st[N];
int tot,nxt[N*2],point[N],v[N*2],cnt=0,ans,h[N];
int f[N][sz],len,bel[N];
ull mul,Mo,Ha[N];
void addline(int x,int y){++tot; nxt[tot]=point[x]; point[x]=tot; v[tot]=y;}
void dfs(int x,int fa)
{
    Ha[x]=Ha[fa]*base+bel[x];
    for (int i=1;i<sz;i++) f[x][i]=f[f[x][i-1]][i-1];
    for (int i=point[x];i;i=nxt[i])
      {
        f[v[i]][0]=x;
        dfs(v[i],x);
      }
}
int find(int x)
{
    for (int i=0;i<sz;i++)
      if ((len>>i)&1) x=f[x][i];
    return x;
}
void answer(int x,int fa)
{
    int father=find(x);
    if (father)
    {
        ull wh=Ha[x]-Ha[father]*mul;
        if (wh==Mo) ans++;
    }
    for (int i=point[x];i;i=nxt[i]) answer(v[i],x);
}
int main()
{
    int n,i,j;
    scanf("%d",&n);cnt=n;
    for (i=2;i<=n;i++)
    {
        int x;scanf("%d%s",&x,&st);
        int ll=strlen(st);
        if (ll==1){bel[i]=st[0];addline(x,i);continue;}
        bel[++cnt]=st[0];addline(x,cnt);
        for (j=1;j<ll-1;j++) bel[++cnt]=st[j],addline(cnt-1,cnt);
        bel[i]=st[ll-1];addline(cnt,i);
    }
    scanf("%s",st);len=strlen(st);
    mul=1;for (i=0;i<len;i++) Mo=Mo*base+st[i],mul*=base;
    dfs(1,0);
    answer(1,0);
    printf("%d",ans);
}