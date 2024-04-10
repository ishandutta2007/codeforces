#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=3e6+7,inf=1e18;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;int qmin(ll&a,ll b){return a>b?a=b,1:0;}
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
typedef unsigned long long ull;int myputs(const char*s){const char*t=s;while(*t)pc(*t++);pc(10);return t-s;}
void writell(ll u,int c=32){ll t=0;for(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
aN v_,w;ll*v=v_+N/2,l,r=inf,x,f,h=1,t;aN m,c,d,j;
int main(){gc=fgc,pc=fpc,atexit(flush);//exit(0);
    ll n=readll()-2;readll();m[0]=0,c[0]=1;rep(i,1,n){w[i]=readll();f^=1,x=w[i]-x;
        if(f==0){for(l<-x&&(l=-x);h<=t&&v[h]<-x;h++);
            (l<=r&&l==-x)||(h<=t&&v[h]==-x)?l=-x,r=w[i]-x,h=c[i]=1,t=0:(h<=t||l<=r)&&(v[++t]=w[i]-x);
            m[i]=std::min(l<=r?x+l:inf,h<=t?x+v[h]:inf);
        }else   {for(r>x &&(r= x);h<=t&&v[t]> x;t--);
            (l<=r&&r== x)||(h<=t&&v[t]== x)?r= x,l=x-w[i],h=c[i]=1,t=0:(h<=t||l<=r)&&(v[--h]=x-w[i]);
            m[i]=std::min(l<=r?x-r:inf,h<=t?x-v[t]:inf);
        }
    }if(l>r&&h>t)return myputs("NO"),0;myputs("YES");d[n]=m[n];per(i,n,1)d[i-1]=c[i]?w[i]:w[i]==d[i]?m[i-1]:w[i]-d[i];
    ll s=d[0],x=0,f=0;rep(i,1,n)qmin(x,s+=(f^=d[i-1]+d[i]!=w[i])?-d[i]:d[i]);writell(-x),writell((s=d[f=0])-x);
    rep(i,1,n)writell((s+=(f^=d[i-1]+d[i]!=w[i])?-d[i]:d[i])-x);fprintf(stderr,"%ld\n",clock());return 0;
}