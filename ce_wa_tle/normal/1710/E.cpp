#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=2e5+7,mod=998244853,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),T=1;
aN a,b,c,d;
void calc(){
    cll n=readll(),m=readll();
    rep(i,1,n)a[i]=readll();
    rep(i,1,m)b[i]=readll();
    cll x=a[1],y=b[1];
    std::sort(a+1,a+n+1);
    std::sort(b+1,b+m+1);
    ll l=0,r=x+y;
    cll tx=std::lower_bound(a+1,a+n+1,x)-a,ty=std::lower_bound(b+1,b+m+1,y)-b;
    while(l<=r){
        cll mid=(l+r)>>1;
        ll sum=0;
        {
            ll j=m;
            rep(i,1,n){
                while(j&&b[j]+a[i]>=mid)d[m-j--+1]=i-1;
                sum+=c[n-i+1]=j;
            }
            while(j)d[m-j--+1]=n;
            //rep(i,1,n)printf("c=%lld\n",c[i]);
            //rep(j,1,m)printf("d=%lld\n",d[j]);
        }
        ll j=0,j0=0,j2=0,now=sum,now0=sum,now2=sum,ans=sum,ans2=sum;
        cll dx=n-tx+1,dy=m-ty+1;
        rep(i,0,n){
            if(i){
                now+=j-c[i],now0+=(j0-(j0>=dy))-c[i];
                if(i!=dx)now2+=j2-c[i];
            }
            //printf("i=%lld j=%lld now=%lld\n",i,j,now);
            while(j<m&&i>=d[j+1])now+=i-d[++j];
            //printf("i=%lld j=%lld now=%lld\n",i,j,now);
            while(j0<m&&i>=d[j0+1])now0+=i-d[++j0],j0==dy-1&&++j0;
            //printf("%lld %lld %lld %lld\n",now0,j0,m,dy);
            while(j2<m&&(i-(i>=dx))>=d[j2+1])now2+=(i-(i>=dx))-d[++j2];
            ans=std::max(ans,now),ans2=std::max(ans2,std::max(now0,now2));
        }
        //printf("%lld %lld %lld %lld %lld\n",mid,dx,dy,ans,ans2);
        if(ans==ans2)r=mid-1;
        else l=mid+1;
    }
    writell(l-1,10);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}