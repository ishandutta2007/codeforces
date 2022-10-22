#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x"in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef unsigned long long ull;
const ll N=4e5+7,mod=1e9+7,iz=1<<21,oz=1<<22,inf=0x3f3f3f3f3f3f3f3f;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1!=o2)fout();
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
aN a,f,p,st;
char s[N],t[N];
int qm(ll&a,ll b){
    return a<b?a=b,1:0;
}
void calc(ll l,ll r){
    ll g=1;
    memset(t+l,'*',r-l);
    while(l<r&&a[l]==1)t[l++]='+';
    if(l==r)return;
    while(a[r]==1)t[--r]='+';
    rep(i,l,r)if((g*=a[i])>mod)return;
    f[l-1]=0;
    rep(i,l,r){
        ll now=a[i];
        f[i]=f[i-1]+a[i],p[i]=i-1;
        if(a[i]!=1)per(j,i-1,l){
            now*=a[j];
            if(qm(f[i],f[j-1]+now))p[i]=j-1;
        }
    }
    ll now=r;
    while(p[now]>=l){
        t[p[now]]='+';
        now=p[now];
    }
}
int main(){
    IO();
    ll n=readll(),lst=1;
    rep(i,1,n)a[i]=readll();
    switch(mygets(s)){
        case 1:
        rep(i,1,n)writell(a[i],i==n?10:s[0]);
        return 0;
        case 2:
        if(s[0]=='-'||s[1]=='-'){
            if(!(s[0]^s[1]^'+'^'-'))rep(i,1,n)writell(a[i],i==n?10:'+');
            if(!(s[0]^s[1]^'*'^'-'))rep(i,1,n)writell(a[i],i==n?10:a[i+1]==0?'-':'*');
            return 0;
        }else case 3:;
        rep(i,1,n)if(a[i]==0)pc(48),pc(i==n?10:'+'),lst=i+1;
        else if(a[i+1]==0){
            calc(lst,i);
            rep(j,lst,i)writell(a[j],t[j]);
            //assert(!t[i]);
            pc(i==n?10:'+');
        }
    }
    return 0;
}
/*
*/