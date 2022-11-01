#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int HEAD[400005],NEXT[400005],E[400005],O,CNT,ll[400005],rr[400005],A,B,C,siz[8000005],LL[8000005],RR[8000005],cntt,head[400005],next[400005],e[400005];
char t[400005],g[400005];
int fa[400005],f[400005],v[400005],n,m,i,cnt,root,len,j,p,o,L1[400005],R1[400005],L,R,S[400005],now,Root[400005];
char s[400005];
bool FLAG;
int Find2(int x,char c)
{
    int now=head[x];
    while (now!=0)
    {
        if (g[now]==c) return e[now];
        now=next[now];
    }
    if (x==1) return 1; else return Find2(f[x],c);
}
void add(int a,int b,int c,char d)
{
    e[a]=c;
    next[a]=head[b];
    head[b]=a;
    g[a]=d;
}
void ADD(int a,int b,int c) {E[a]=c;NEXT[a]=HEAD[b];HEAD[b]=a;}
void dfs(int x)
{
    ll[x]=++CNT;
    int now=HEAD[x];
    while (now!=0) {dfs(E[now]);now=NEXT[now];}
    rr[x]=CNT;
}
void Update(int &A,int &B,int l,int r,int t)
{
    if (!B) B=++cntt;
    siz[B]=siz[A]+1; if (l==r) return;
    int mid=(l+r)/2;
    if (t<=mid) Update(LL[A],LL[B],l,mid,t); else
      Update(RR[A],RR[B],mid+1,r,t);
    if (!RR[B]) RR[B]=RR[A];
    if (!LL[B]) LL[B]=LL[A];
}
int Find(int A,int B,int l,int r,int L,int R)
{
    if (l==L && r==R) return siz[A]-siz[B];
    int mid=(l+r)/2,p=0,q=0;
    if (L<=mid) p=Find(LL[A],LL[B],l,mid,L,min(mid,R));
    if (R>mid) q=Find(RR[A],RR[B],mid+1,r,max(mid+1,L),R);
    return p+q;
}
int main()
{
    scanf("%d%d",&n,&m); cnt=1;
    for (i=1; i<=n; i++)
    {
        scanf("%s",s);
        len=strlen(s); root=1;
        for (j=0; j<len; j++)
        {
            p=head[root]; FLAG=false;
            while (p!=0)
            {
                if (g[p]==s[j]) {root=e[p]; FLAG=true; break;}
                p=next[p];
            }
            if (!FLAG)
            {
                cnt++; add(++o,root,cnt,s[j]);
                fa[cnt]=root; root=cnt; t[cnt]=s[j];
            }
        }
        v[i]=root;
    }
    L=0; R=1; S[1]=1; f[1]=1;
    while (L!=R)
    {
        now=S[++L]; if (fa[now]==1 || now==1) f[now]=1; else f[now]=Find2(f[fa[now]],t[now]);
        p=head[now];
        while (p!=0) {S[++R]=e[p]; p=next[p];}
    }
    for (i=2; i<=cnt; i++) ADD(++O,f[i],i);
    dfs(1); CNT=0;
    for (i=1; i<=n; i++) {L1[i]=CNT+1; for (j=v[i]; j; j=fa[j]) {CNT++; Update(Root[CNT-1],Root[CNT],1,cnt,ll[j]);} R1[i]=CNT;}
    while (m--)
    {
        scanf("%d%d%d",&A,&B,&C);
        printf("%d\n",Find(Root[R1[B]],Root[L1[A]-1],1,cnt,ll[v[C]],rr[v[C]]));
    }
    return 0;
}