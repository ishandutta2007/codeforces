#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=;i;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    //return 0;
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
aN next,to,head,w,dis,in;
ll q[2400400],*q_=q+1200000;
ll cnt;
void add(cll u,cll v,cll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
aN h,t;
void get_sp_(cll n){
    //printf("???");
    struct node{
        ll u,d;
        operator ll()const{
            return-d;
        }
        int check()const{
            return dis[u]==d;
        }
    };
    static std::priority_queue<node>qu;
    while(!qu.empty())qu.pop();
    rep(i,1,n)qu.push((node){i,dis[i]});
    while(!qu.empty()){
        cll u=qu.top().u;
        qu.pop();
        rev(i,u,v)if(dis[v]>dis[u]+w[i])dis[v]=dis[u]+w[i],qu.push((node){v,dis[v]});
        while(!qu.empty()&&!qu.top().check())qu.pop();
    }
}
void get_sp(cll n,cll m){
    //return get_sp_(n);
    ll t=0,cnt=0;
    ull sum=0;
    cll lim=6*(n+m);
    rep(i,1,n)q[++t]=i,sum+=dis[i],in[i]=0;
    rep(h,1,t){
        cll u=q[h];
        if(__builtin_expect(++cnt>lim,0))return get_sp_(n);
        if((ull)dis[u]*(t-h+1)>sum){q[++t]=u;continue;}
        sum-=dis[u],in[u]=0;
        rev(i,u,v){
            if(__builtin_expect(++cnt>lim,0))return get_sp_(n);
            if(dis[v]>dis[u]+w[i]){
                dis[v]=dis[u]+w[i];
                if(in[v])continue;
                sum+=dis[v],in[v]=1;
                if(h<t&&dis[v]<dis[q[h+1]])q[h--]=v;
                else q[++t]=v;
            }
        }
    }
}
void calc(cll n){
    aN fz;
    rep(i,1,n)fz[i]=dis[i]+i*i;
    ll t=0,h=1;
    rep(i,1,n){
        while(h<t&&(i-q[t])*(fz[q[t]]-fz[q[t-1]])-(q[t]-q[t-1])*(fz[i]-fz[q[t]])>=0)t--;
        q[++t]=i;
    }
    rep(i,1,n){
        while(h<t&&fz[q[h]]-2*i*q[h]>=fz[q[h+1]]-2*i*q[h+1])h++;
        dis[i]=fz[q[h]]-2*i*q[h]+i*i;
        //rep(j,1,n)assert(dis[i]<=fz[j]-2*i*j+i*i);
    }
}
std::mt19937_64 rd;
void calc(){
    //cll n=100000,m=100000,k=20;
    cll n=readll(),m=readll(),k=readll();
    memset(head,cnt=0,(n+1)<<3);
    rep(i,1,m){
        //cll u=rd()%n+1,v=rd()%n+1,c=rd()%100000000;
        cll u=readll(),v=readll(),c=readll();
        add(u,v,c),add(v,u,c);
    }
    rep(i,1,n)dis[i]=1e14;
    dis[1]=0,get_sp(n,m);
    rep(i,1,k)calc(n),get_sp(n,m);
    rep(i,1,n)writell(dis[i],i==n?10:32);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}