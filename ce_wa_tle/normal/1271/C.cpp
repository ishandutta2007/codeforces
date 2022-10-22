#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=1e6+7,mod=1e9+7,m2=1e9+9;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;typedef long double ld;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}ll t[4];
const ll dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int main(){
    ll n=readll(),sx=readll(),sy=readll(),x=0,y=0,ans=-1;
    rep(i,1,n)x=readll(),y=readll(),x>sx&&++t[0],x<sx&&++t[2],y>sy&&++t[1],y<sy&&++t[3];
    rep(i,0,3)if(t[i]>ans)x=sx+dx[i],y=sy+dy[i],ans=t[i];
    ans?printf("%lld\n%lld %lld\n",ans,x,y):printf("0\n%d %d\n",!sx,!sy);return 0;
}