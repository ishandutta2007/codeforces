#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126){
    if(l>r)std::swap(l,r);
    int c=gc();
    for(;c<l||c>r;c=gc());
    return c;
}
ll readll(){
    ll x=0,w=1;
    int c=gc();
    for(;c<48||c>57;c=gc())c-45||(w=-w);
    for(;c>47&&c<58;c=gc())x=x*10+c-48;
    return x*w;
}
void writell(ll u,int c=32){
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10^48;
    for(t||pc(48);t;)pc(wt[t--]);
    c&&pc(c);
}
int mygets(char*s,int c=0){
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
aN t,s,z,c,f,l,r,lc,rc,inv,fs,fc,ifs;
int qm(ll&a,ll b=mod){
    return a>=b?a-=b,1:0;
}
int main(){
    IO();
    const ll n=readll(),m=readll();
    inv[1]=1,inv[2]=(mod+1)/2;
    rep(i,3,n)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    rep(i,1,n)t[s[i]=readll()]++;
    rep(i,1,n)z[i]=t[i],f[i]=t[i-1]+1,t[i]+=t[i-1];
    rep(i,1,n)c[++t[s[i]-1]]=i;
    rep(i,1,m){
        const ll a=readll(),b=readll();
        if(b>z[a])continue;
        l[c[f[a]+b-1]]++,r[c[f[a]+z[a]-b]]--,rc[a]++;
    }
    ll nows=1,nowc=0;
    rep(i,1,n){
        if(const ll rs=rc[i])fc[i]=1,ifs[i]=inv[fs[i]=rs];
        else fc[i]=0,ifs[i]=fs[i]=1;
        nowc+=fc[i],nows=nows*fs[i]%mod;
    }
    ll anss=nows,ansc=nowc;
    rep(i,1,n){
        const ll c=s[i];
        nowc-=fc[c],nows=nows*ifs[c]%mod,lc[c]+=l[i],rc[c]+=r[i];
        if(const ll ls=l[i]){
            const ll g=rc[c]-(lc[c]<=rc[c]),ac=2-!g,as=(g+!g)*ls;
            const ll tc=nowc+ac,ts=nows*as%mod;
            if(tc>ansc)ansc=tc,anss=0;
            if(tc==ansc)qm(anss+=ts);
        }
        const ll ls=lc[c],rs=rc[c];
        if(const ll s2=ls*rs-std::min(ls,rs))fc[c]=2,ifs[c]=inv[ls-!(ls<rs)]*inv[rs-(ls<rs)]%mod,fs[c]=s2;
        else if(const ll s1=ls+rs)fc[c]=1,ifs[c]=inv[fs[c]=s1];
        else fc[c]=0,ifs[c]=fs[c]=1;
        nowc+=fc[c],nows=nows*fs[c]%mod;
    }
    writell(ansc),writell(anss,10);
    return 0;
}