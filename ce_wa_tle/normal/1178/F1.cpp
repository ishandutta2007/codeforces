#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=1e3+7,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;typedef long double ld;const ld eps=1e-6;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}aN a,f[N],g,hd,nx;
int main(){
    ll n=readll(),m=readll(),t=0;rep(i,1,m)a[++t]=readll(),a[t]==a[t-1]&&--t;if(m>2*n)return puts("0"),0;
    m=t;per(i,m,1)nx[i]=hd[a[i]],hd[a[i]]=i;rep(i,1,n+1)f[i][i-1]=1;per(i,n,1){ll s=1,l=hd[i],r=l;
    rfor(ll v=nx[l];v;v=nx[v])s=s*f[r+1][v-1]%mod,r=v;
    per(j,l,1){g[j]=0;if(a[j]>=i)per(k,l,j)g[j]=(g[j]+f[j][k-1]*f[k][l-1]%mod)%mod;}
    rep(k,r,m){g[k]=0;if(a[k]>=i)rep(j,r,k)g[k]=(g[k]+f[j+1][k]*f[r+1][j]%mod)%mod;}g[l]=g[r]=1;
    per(j,l,1)if(a[j]>=i)rep(k,r,m)if(a[k]>=i)f[j][k]=g[j]*g[k]*s%mod;//printf("%lld\n",f[3][3]);
    }
    printf("%lld\n",f[1][m]);return 0;
}