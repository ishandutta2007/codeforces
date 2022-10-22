#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=5e6+7,inf=1e18L+7;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}aN jc_,f,t,a,s,e;
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;int qmax(ll&a,ll b){return a<b?a=b,1:0;}
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=getchar());for(;c>=48&&c<=57;x=x*10+(c&15),c=getchar());return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}ll*jc=jc_+1,flag=0;
int calc(int cases){
    ll n=readll(),k=readll()-1,r=0;if(flag){if(cases==106)printf("%lld %lld\n",n,k+1);else return 0;}
    if(k>=f[n])return puts("-1");rep(i,1,n)t[s[i]=e[i]=i]=0;
    rep(i,1,n){if(r==i-1){r=i;while(r<n&&k/jc[r-i-1]>=f[n-r])k-=jc[r-i-1]*f[n-r],r++;t[a[i]=r]=1,s[r]=0,e[i]=r;}
    else{ll now=1;while(now<r-1&&(t[now]||now==s[i]||(k/jc[r-i-1]>=f[n-r])))t[now]||now==s[i]||(k-=jc[r-i-1]*f[n-r]),now++;
    while((t[now]||now==s[i])&&now>1)now--;t[a[i]=now]=1,e[s[i]]=e[now],e[now]!=r&&(s[e[now]]=s[i]);}}
    rep(i,1,n)printf("%lld ",a[i]);return puts("");
}int main(){ll T=readll(),cnt=0;if(T>10)flag=0;jc[-1]=jc[0]=f[0]=1;rep(i,1,50){jc[i]=inf/jc[i-1]<i?inf:jc[i-1]*i;
rep(j,1,i)f[i]=(inf-f[i])/f[i-j]<jc[j-2]?inf:f[i-j]*jc[j-2]+f[i];}while(T --> 0)calc(++cnt);return 0;}
/*
4
6 60
6 61
6 62
6 63
*/