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
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
void writell(cll u,int c=32){
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
aN nx,hd;
aN a,b;
int main(){
    IO();
    cll n=readll();
    ll s=0;
    rep(i,1,n){
        cll x=readll();
        s+=x,nx[i]=hd[x],hd[x]=i;
    }
    if(s&1||s/2<n-1)return!myputs("-1");
    ll h=1,t=n,tj=n|1,now=0;
    while(1){
        while(h<=t&&!hd[h])h++;
        while(h<=t&&!hd[t])t--;
        while(h<=tj&&!hd[tj])tj-=2;
        /*printf("h=%lld t=%lld\n",h,t);
        ll l=0,o=0,s=0,n=0;
        rep(i,h,t)rfor(ll x=hd[i];x;x=nx[x])n++,l+=i==1,o+=i&1,s+=i,printf("%lld ",i);pc(10);
        ll c=s/2-n+1;
        printf("%lld %lld\n",c,(n-1-std::max(o/2,l))/2);*/
        if(h>t)break;
        if(h>2)return!myputs("-1");
        if(h==1){
            if(t==1){
                if(!nx[nx[hd[1]]]){
                    a[++now]=hd[1],b[now]=nx[hd[1]];
                    break;
                }
                return!myputs("-1");
            }
            cll g=tj!=1&&hd[tj]?tj:t,t=g;
            cll x=hd[h],y=hd[t];
            hd[h]=nx[x],hd[t]=nx[y];
            a[++now]=x,b[now]=y;
            nx[y]=hd[t-1],hd[t-1]=y;
            if(~t&1&&t-1>tj)tj=t-1;
        }
        if(h==2){
            if(t==2){
                cll x=hd[h];
                ll y=x;
                if(!nx[nx[y]])return!myputs("-1");
                while(nx[y])a[++now]=y,b[now]=nx[y],y=nx[y];
                a[++now]=x,b[now]=y;
                break;
            }
            cll x=hd[h],y=nx[x],z=hd[t];
            if(!y)return!myputs("-1");
            hd[h]=nx[y],hd[t]=nx[z];
            a[++now]=x,b[now]=y;
            a[++now]=x,b[now]=z;
            a[++now]=y,b[now]=z;
            nx[z]=hd[t-2],hd[t-2]=z;
            if(t-2==1&&h!=1)h=1;
        }
    }
    writell(now,10);
    rep(i,1,now)writell(2),writell(a[i]),writell(b[i],10);
    return 0;
}
/*
20
1 1 1 1 1 1 1 1 1 2 2 2 2 2 3 3 3 3 4 7
*/