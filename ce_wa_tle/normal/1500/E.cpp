#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=3e6+7,inf=1e18;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s){const char*t=s;while(*t)pc(*t++);pc(10);return t-s;}int qm(ll&a,ll b){return a>b?a=b,1:0;}
void writell(ll u,int c=32){ll t=0;for(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
struct node{ll t,s,l,r;};aN x,f,c,s;struct bit{node f[N];ll n,m;void set(ll n_){for(n=1;n<n_;n<<=1);}
ll pre(ll k)const{ll u=0,s=0;red(i,n)if(u!=n&&k>=f[u+i].t)s+=f[u+=i].s,k-=f[u].t;return s;}ll suf(ll k){return f[n].s-pre(f[n].t-k);}
ll Pre(ll k)const{ll u=0,s=0,l=0;red(i,n)if(u!=n&&k>=f[u+i].t)u+=i,l+=f[u].l+s*f[u].t,s+=f[u].s,k-=f[u].t;return l;}
ll Suf(ll k)const{k=f[n].t-k;ll u=0,t=0,s=0,r=0;red(i,n)if(u!=n&&k>=f[u+i].t+t)u+=i,r+=f[u].r+t*f[u].s,s+=f[u].s,t+=f[u].t;return f[n].r-r-t*(f[n].s-s);}
void update(ll u,ll c){rfor(ll d=x[u],dt=!~-c,ds=(d&-!~-c),s=f[u].s+ds,t=f[u].t+dt,e=0;u<=n;e=u,u=(u&~-u)|(u&-u)<<1)
e>u?s+=f[u].s,t+=f[u].t:(f[u].l+=(s+d*(f[u].t+dt-t))*c,f[u].r+=(t*d+(f[u].s+ds-s))*c,f[u].t+=c,f[u].s+=d*c);}}t;
ll getans(){ll n=t.n,m=t.f[n].t,l=1,r=m/2;while(l<=r){ll mid=(l+r)>>1;if(t.pre(mid+1)>t.suf(mid))l=mid+1;else r=mid-1;}
return l-1==m/2?t.f[n].r-t.f[n].l:t.f[n].s+2*(t.Suf(l-1)-t.Pre(l-1)-t.pre(l));}
struct cmp{const ll*const a;cmp(const ll*b):a(b){}int operator()(ll x,ll y)const{return a[x]<a[y];}};
int main(){IO();
    ll n=readll(),m=readll(),tx=0;rep(i,1,n+m)i>n&&(f[i]=readll()),s[c[i]=i]=readll();std::sort(c+1,c+n+m+1,cmp(s));
    rep(i,1,n+m)s[c[i]]!=x[tx]&&(x[++tx]=s[c[i]]),s[c[i]]=tx;t.set(tx);rep(i,1,n)t.update(s[i],1);
    writell(getans(),10);rep(i,n+1,n+m)t.update(s[i],f[i]*-2+3),writell(getans(),10);return 0;
}
/*
5 0
1 2 3 4 5
l= 1  3  6 10
r= 5  9 12 14
12 10
810 637 786 798 620 713
741 674 792 816 611 780
2 780
2 713
2 786
2 741
2 620
2 674
1 808
1 609
1 708
1 659
*/