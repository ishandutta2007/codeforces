#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=4e5+7,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;ll n,m;aN a;
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}int qm(ll&a,ll b){return a<b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}static inline int check(ll u){u-=u>>1&5;return(u>>2)+(u&3)==2;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
struct ss{ll t,w[4],c[4];ll find(ll u){ref(i,0,t)if(w[i]==u)return c[i];return a[u];}void print(){ll s=0;rep(i,1,m)writell(s<t&&w[s]==i?c[s++]:a[i]);pc(10);}
friend ll operator^(const ss&a,const ss&b){ll j=0,s=a.t+b.t;ref(i,0,a.t){while(j+1<b.t&&b.w[j+1]<=a.w[i])j++;s-=b.w[j]==a.w[i]?1+(b.c[j]==a.c[i]):0;};return s;}
void push(ll u,ll v){t<4&&(w[t]=u,c[t]=v),t++;}}p[N];void check(){rep(i,1,n)if((p[1]^p[i])>2)return;myputs("Yes"),p[1].print(),exit(0);}
int main(){IO();n=readll(),m=readll();ll x,f;rep(i,1,m)a[i]=readll();rep(i,2,n)rep(j,1,m)if((x=readll())!=a[j])p[i].push(j,x);ll s=1;rep(i,1,n)if(p[i].t>p[s].t)s=i;if(p[s].t>4)return!myputs("No");
if(p[s].t<=2)return myputs("Yes"),p[1].print(),0;if(p[s].t==3)ref(g,0,3){x=p[f=1].t=0;p[1].push(p[s].w[g],p[s].c[g]);rep(i,1,n){switch(p[1]^p[i]){case 3:x=i;break;case 4:f=0;};if(!f)break;}
if(!f)continue;if(!x)return myputs("Yes"),p[1].print(),0;ref(h,0,3)if(g!=h){p[1].t=0;ref(t,0,3)if(t==g)p[1].push(p[s].w[g],p[s].c[g]);else if(t==h)p[1].push(p[s].w[h],p[x].find(p[s].w[h]));check();}}
else ref(y,0,1<<p[s].t)if(check(y)){ref(i,p[1].t=0,p[s].t)if(y>>i&1)p[1].push(p[s].w[i],p[s].c[i]);check();}return!myputs("No");}