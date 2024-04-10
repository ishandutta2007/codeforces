#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=1e6+7,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;typedef long double ld;const ld eps=1e-6;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}aN a,t;
int main(){
    ll n=0;rfor(ll c=readchar();c>=97&&c<=99;c=gc())a[++n]=c-97;
    ll l=0,r=n+1,q=0;while(l+2<r-2){
        if(a[l+1]==a[r-1]){t[++q]=a[l+=1],r-=1;continue;}
        if(a[l+1]==a[r-2]){t[++q]=a[l+=1],r-=2;continue;}
        if(a[l+2]==a[r-1]){t[++q]=a[l+=2],r-=1;continue;}
        if(a[l+2]==a[r-2]){t[++q]=a[l+=2],r-=2;continue;}
    }rep(i,1,q)pc(t[i]+97);if(l+1<=r-1)pc(a[l+1]+97);per(i,q,1)pc(t[i]+97);return 0;
}