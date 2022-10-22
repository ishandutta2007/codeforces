#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)r(ll i=s;i;i=(i-1)&(s))
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
struct val{
    ll v[3];
    val(){v[0]=v[1]=v[2]=-mod;}
    void add(ll u){
        if(u<=v[2])return;
        v[u>v[1]?v[2]=v[1],u>v[0]?v[1]=v[0],0:1:2]=u;
    }
    ll getpre(ll u)const{
        ll sum=0;
        ref(i,0,u)sum+=v[i];
        return sum;
    }
    ll getpre_(ll u)const{
        ll sum=0;
        ref(i,0,u-1)sum+=v[i];
        return sum+v[u];
    }
}z,f,ans;
int main(){
    //IO();
    ll n=readll();
    if(n==1)return writell(readll()),0;
    ll sum=0,del=0,fsum=0;
    rep(i,1,n){
        const ll x=readll();
        sum+=llabs(x),del+=i&1?x:-x;
        if(x<=0)f.add(x),fsum++;
        else z.add(-x);
    }
    const ll left=(fsum-(1-n))%3;
    if(left)ans.add(z.getpre(3-left)),ans.add(z.getpre_(3-left)),ans.add(f.getpre(left)),ans.add(f.getpre_(left));
    else ans.add(0),ans.add(z.v[0]+f.v[0]),ans.add(z.getpre(3)),ans.add(f.getpre(3));
    writell(2*ans.v[n&1&&del==2*ans.v[0]+sum]+sum);
    return 0;
}