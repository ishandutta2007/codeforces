#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
#define U 20
Edg
int up[SZ][U],D=0,n,fs[SZ],ed[SZ],dep[SZ],la[SZ],lb[SZ],lw[SZ];
vector<int> ls[SZ];
void dfs(int x,int f=0)
{
    up[x][0]=f; dep[x]=dep[f]+1; fs[x]=++D;
    for(int i=1;i<U;i++)
        up[x][i]=up[up[x][i-1]][i-1];
    for esb(x,e,b) if(b!=f) dfs(b,x); ed[x]=++D;
}
int jump(int a,int d)
{
    for(int g=U-1;g>=0;--g)
        if(dep[up[a][g]]>=d) a=up[a][g];
    if(dep[a]!=d) throw "jump error";
    return a;
}
int lca(int a,int b)
{
    if(dep[a]>=dep[b]) swap(a,b);
    //dep[a]<=dep[b]
    b=jump(b,dep[a]);
    if(a==b) return a;
    for(int g=U-1;g>=0;--g)
        if(up[a][g]!=up[b][g])
            a=up[a][g],b=up[b][g];
    return up[a][0];
}
ll g[SZ],f[SZ],bb[SZ];
ll qsum(int x)
{
    ll s=0;
    for(;x>=1;x-=x&-x) s+=bb[x];
    return s;
}
void edt(int x,int y)
{
    for(;x<=D;x+=x&-x) bb[x]+=y;
}
void dp(int x,int fa=0)
{
    g[x]=0;
    for esb(x,e,b) if(b!=fa)
        dp(b,x),g[x]+=f[b];
    f[x]=g[x];
    for(unsigned _=0;_<ls[x].size();++_)
    {
        int l=ls[x][_],a=la[l],b=lb[l];
        ll cur=lw[l]+g[x]+qsum(fs[a])+qsum(fs[b]);
        if(fa) cur-=qsum(fs[up[x][0]])*2;
        f[x]=max(f[x],cur);
    }
    edt(fs[x],g[x]-f[x]);
    edt(ed[x],f[x]-g[x]);
}
int main()
{
    memset(fst,0,sizeof fst);
    memset(bb,0,sizeof bb);
    M=D=0; int q; scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) ls[i].clear();
    for(int i=2;i<=n;i++)
    {
        int p; scanf("%d",&p);
        adde(p,i);
    }
    dfs(1);
    for(int i=1;i<=q;i++)
        scanf("%d%d%d",la+i,lb+i,lw+i),
        ls[lca(la[i],lb[i])].pb(i);
    dp(1); printf("%lld\n",max(f[1],0LL));
}