#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=407,mod=1e9+7;typedef ll aN[N],aN2[N*N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}aN2 u,v;ll t;
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;typedef long double ld,dNN[N][N],dN[N];
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}dN a,b;aN f[N],d;
dNN s_[3],*s=s_+1,p;int check(ll a){return a<2&&a>-2;}template<class T>T qmax(T&a,T b){T s=b-a;return s>0?a=b,s:0;}
template<class T>T qmin(T&a,T b){T s=a-b;return s>0?a=b,s:0;}ll pt[N][N],bt[N];
void calc(ll x,ll y,ld z){if(x>=0)b[x]=(bt[x]!=t?bt[x]=t,0:b[x])+qmax(pt[x][y]!=t?pt[x][y]=t,p[x][y]=0:p[x][y],z);}
int main(){
    ll n=readll(),m=readll(),x;const ld nn=1.0L/n;ld ans=nn;memset(f,0x3f,sizeof f);
    rep(i,1,m)d[u[i]=readll()]++,d[v[i]=readll()]++,f[u[i]][v[i]]=f[v[i]][u[i]]=1;
    rep(i,1,n)f[i][i]=0;rep(k,1,n)rep(i,1,n)rep(j,1,n)qmin(f[i][j],f[i][k]+f[k][j]);
    rep(i,1,n)rep(j,1,m)if(check(x=f[i][v[j]]-f[i][u[j]]))s[x][i][u[j]]+=1.0L/d[v[j]],s[-x][i][v[j]]+=1.0L/d[u[j]];
    rep(i,1,n)rep(k,-1,1)rep(j,1,n)s[k][i][j]*=nn;rep(i,1,n){memset(a,0,sizeof a),memset(b,0,sizeof b);
    rep(j,1,n)a[f[i][j]]=nn;rep(j,1,n){++t;rep(k,1,n)rep(l,-1,1)calc(f[i][k]+l,f[j][k],s[l][i][k]);
    rep(k,0,n)qmax(a[k],b[k]);}ld sum=0;rep(j,0,n)sum+=a[j];qmax(ans,sum);}printf("%.12lf\n",(double)ans);return 0;
}