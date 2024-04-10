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
const char r[]="0001";
char v2[N];
ll t,s[1111];
ll gcd(ll a,ll b){
    while(b)std::swap(a%=b,b);
    return a;
}
int main(){
    //IO();
    const ll a=readll();
    if(a==1)return!myputs("1");
    rep(i,1,1000)s[i]=s[i/10]+(i%10);
    v2[0]=48;
    ll t=1,now=1,sum=0,sa=0,g;
    const ll sb=s[a]*a-1;
    while(now){
        if(t>=4&&v2[t-1]!=57&&(sa=sum+1-a*(s[a-now]+1))>=0&&sa*4+sb*t<=500000*(g=gcd(sa,sb))){
            v2[t-1]++;
            break;
        }
        const ll s=(now*=10)/a;
        sum+=s,v2[t++]=s^48,now-=s*a;
    }
    if(!now){
        if(sum<a)return!myputs("-1");
        else if(sum==a){
            const char*g=v2;
            while(*g==48)g++;
            fwrite(g,t-(g-v2),1,stdout);
            return 0;
        }
        sa=sum-a,g=gcd(sa,sb);
    }
    ll ta=sa/g,tb=sb/g;
    if(ta)pc(49),ta--;
    else{
        const char*g=v2;
        while(*g==48)g++;
        fwrite(g,t-(g-v2),1,stdout),tb--;
    }
    rep(i,1,ta)fwrite(r,4,1,stdout);
    rep(i,1,tb)fwrite(v2,t,1,stdout);
    return 0;
}