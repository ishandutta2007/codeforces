#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=5e3+7,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;int h[N][N],g[N][N];aN a,f[N];
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=getchar());for(;c>=48&&c<=57;x=x*10+(c&15),c=getchar());return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}
int qmin(ll&a,ll b){return a>b?a=b,1:0;}int qmod(ll&a,ll b=mod){return a>b?a-=b,1:0;}
int main(){
    a[1]=readchar()&1;ll n=1,c=gc(),sum=0,now=0,w=1,min=mod;for(;c>32;a[++n]=c&1,c=gc());a[n+1]=a[0]=f[0][1]=1;
    per(i,n,0)per(j,n,1)h[i][j]=a[i]^a[j]?0:h[i+1][j+1]+1;
    rep(i,0,n)rep(j,i+1,n+1)h[i][j]=h[i][j]<j-i?a[i+h[i][j]]<a[j+h[i][j]]:1;
    rep(i,1,n)if(a[i]){ll k=i-1,s=0,m=n;rep(j,i+1,n+1)if(a[j]){while(k>=0&&(j-i>i-k||(j-i==i-k&&h[k][i])))
    f[k][i]&&(qmod(s+=f[k][i]),qmin(m,g[k][i])),k--;f[i][j]=s,g[i][j]=m+1;}qmod(sum+=f[i][n+1]);}
	per(i,n,1)a[i]&&qmod(now+=w),f[i][n+1]&&(w<n?qmin(min,g[i][n+1]+now):min==mod&&qmod(min=g[i][n+1]+now)),qmod(w*=2);
    printf("%lld\n%lld\n",sum,min);return 0;
}