#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
bool p1;typedef long long ll;const ll N=1e6+7,mod=1e9+7;typedef ll aN[N];int(*gc)()=getchar;int(*pc)(int)=putchar;
inline int fgc(){static char s[1<<22],*p1=s,*p2=s;return p1==p2&&(p2=(p1=s)+fread(s,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
char ouf[1<<22],*ous=ouf;inline int fpc(int c){return*ous++=c;}void flush(){fwrite(ouf,ous-ouf,1,stdout);}
ll readll(){
    ll x=0,w=1;char c=gc();for(;c<'0'||c>'9';c-'-'||(w=-w),c=gc());for(;c>='0'&&c<='9';x=x*10+(c^48),c=gc());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}
aN a[2],c[2],b_[2],s;ll*b[]={b_[0]+N/2,b_[1]+N/2};void link(ll x,ll v){v=v<0?-v:v;s[b[x][v]]=b[x][-v];}
int main(){
    ll n=readll();rep(i,1,2*n)rep(j,0,1)b[j][a[j][i]=c[j][i]=readll()]=i;ll lst=0;
    rep(i,1,2*n)if(!s[i]){ll d=0,x=i,y=0,z=0;s[x]=-1;while(!s[b[d][-a[d][x]]]){y=x,x=b[d][-a[d][x]];
    if(a[0][y]*a[1][y]<0)z=b[d^1][-a[d^1][y]],z=b[d][a[d][z]],link(0,a[0][y]),link(1,a[1][y]),
    (a[0][x]*a[1][x]>0)&&(std::swap(b[d^1][a[d^1][x]],b[d][a[d][z]]),0),
    a[d][x]=a[d][z],a[d^1][z]=a[d^1][x];s[x]=s[x]?:-1,d^=1;}
    if(a[0][x]*a[1][x]<0||a[d][x]!=-a[d][b[d^1][-a[d^1][x]]])return puts("NO"),0;y=b[d^1][-a[d^1][x]];
    if(a[d][x]<a[d][y])std::swap(x,y),d^=1;
    s[b[d][a[d][x]]]=b[d^1][a[d^1][y]],s[lst]=b[d^1][a[d^1][x]],lst=b[d][a[d][y]];}
    puts("YES");ll x=0;rep(i,1,2*n)x=s[x],printf("%lld %lld\n",c[0][x],c[1][x]);return 0;
}/*rep(j,0,1){rep(i,1,2*n)printf("%lld ",a[j][i]);puts("");}
    
    rep(j,0,1){rep(i,1,2*n)printf("%2lld ",a[j][i]);puts("");}
    rep(j,0,1)rep(i,-n,n)printf("b[%lld][%lld]=%lld\n",j,i,b[j][i]);
    rep(i,1,2*n)printf("%lld->%lld\n",i,s[i]);*/
//{         y } {x}
//[[o]r[o]r[o]]r[o]gororogorogor
//d= (0) (1)   0
/*
2
1 2
-1 -1
-2 1
2 -2
3
-3 -3
3 -1
1 1
-1 -2
2 2
-2 3
4
-4 4
4 -1
3 1
-3 3
-2 -3
2 -2
1 2
-1 -4
*/