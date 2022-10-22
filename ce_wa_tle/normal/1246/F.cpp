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
const ll N=1e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
char s[126];
ll lst[26];
aN t,pre[26],nxt[26],l,r,nl,nr,lw[17],rw[17],ls[17],rs[17];
int qmin(ll&a,ll b){
    return a>b?a=b,1:0;
}
int qmax(ll&a,ll b){
    return a<b?a=b,1:0;
}
int main(){
    IO();
    const ll n=mygets(s+1);
    rep(i,1,n)s[i]-=97;
    rep(i,1,n)rfor(ll u=(l[i]=lst[s[i]],l[lst[s[i]]=i]);u<i;)++u,nxt[t[u]++][u]=i;
    ref(i,0,26)rfor(ll&u=lst[i];u<=n;)++u,nxt[t[u]++][u]=n+1;
    memset(t,0,(n+1)<<3);
    per(i,n,1)rfor(ll u=(r[i]=lst[s[i]],r[lst[s[i]]=i]);u>i;)--u,pre[t[u]++][u]=i;
    rep(i,1,n)nl[i]=nr[i]=lw[0][i]=i,l[i]=l[i]?:1,r[i]=r[i]==n+1?n:r[i];
    r[0]=0,l[n+1]=n+1;
    ll sum=0;
    rep(t,1,26){
        rep(i,1,n)qmin(lw[0][i],l[nxt[t-1][i]]),qmax(rw[0][i],r[pre[t-1][i]]),ls[0][i]=rs[0][i]=i;
        ref(j,0,16)rep(i,1,n)lw[j+1][i]=lw[j][lw[j][i]],rw[j+1][i]=rw[j][rw[j][i]],ls[j+1][i]=ls[j][i]+ls[j][lw[j][i]],rs[j+1][i]=rs[j][i]+rs[j][rw[j][i]];
        rep(i,1,n){
            if(nl[i]==1&&nr[i]==n)continue;
            if(t<26&&nr[i]>=nxt[t][nl[i]])continue;
            per(j,16,0){
                ll&pl=nl[i],&pr=nr[i];
                const ll sl=lw[j][pl],sr=rw[j][pr];
                if(t==26||sr<nxt[t][sl])sum+=((n-1)<<j)-rs[j][pr]+ls[j][pl],pl=sl,pr=sr;
            }
            sum+=n-1-nr[i]+nl[i],nl[i]=lw[0][nl[i]],nr[i]=rw[0][nr[i]];
        }
    }
    writell(sum);
    return 0;
}