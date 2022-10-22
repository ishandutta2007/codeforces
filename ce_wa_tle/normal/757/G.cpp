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
cll IO_res=IO(),n=readll(),q=readll();
aN next,to,head,w;
ll cnt;
void add(cll u,cll v,cll c){
    next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;
}
struct cmp_t{
    cll*const s;
    cmp_t(cll*s_):s(s_){}
    int operator()(cll a,cll b)const{
        return s[a]<s[b];
    }
};
struct tr{
    typedef ll aM[N*8];
    aM ls,rs,val,sum;
    aN rt,st,dfn,end,vis,sz,a;
    aN dis[22];
    const cmp_t cmp;
    tr():cmp(sz){}
    ll cnt,n,top;
    ll findroot(cll u,cll fa,cll n){
        sz[u]=1;
        ll flag=0;
        rev(i,u,v)if(!vis[v]&&v^fa)flag=findroot(v,u,n)?:flag,sz[u]+=sz[v];
        if(!flag&&sz[u]*2>=n)flag=u;
        return flag;
    }
    void getdis(cll u,cll fa,cll cnt){
        sz[u]=1;
        rev(i,u,v)if(!vis[v]&&v^fa)dis[cnt][v]=dis[cnt][u]+w[i],getdis(v,u,cnt),sz[u]+=sz[v];
    }
    ll build(cll g,cll n,cll c){
        //printf("%lld %lld\n",g,n);
        static aN s,q;
        static ll t;
        cll u=findroot(g,0,n);
        getdis(u,0,c);
        assert(sz[u]==n);
        //printf("u=%lld %lld\n",u,c);
        vis[u]=1;
        ll lt=t,h=t+1,qh=1,qt=0;
        rev(i,u,v)if(!vis[v])s[++t]=build(v,sz[v],c+1);
        if(h==t+1)return t=lt,u;
        std::sort(s+lt+1,s+t+1,cmp);
        struct{
            const ll*s,*q;
            ll&h,&t,&qh,&qt;
            const cmp_t cmp;
            operator ll(){
                return h>t||(qh<=qt&&cmp(q[qh],s[h]))?qh<=qt?q[qh++]:0:s[h++];
            }
        }min={s,q,h,t,qh,qt,cmp};
        //printf("%lld==%lld\n",u,t-h+1+qt-qh+1);
        while(t-h+1+qt-qh+1>2)ls[++cnt]=min,rs[cnt]=min,sz[cnt]=sz[ls[cnt]]+sz[rs[cnt]],q[++qt]=cnt;
        ls[u]=min,rs[u]=min,t=lt;
        return u;
    }
    void update(ll&u,cll v,cll id,cll z,cll c){
        //printf("%lld %lld %lld %lld %lld %lld %lld\n",u,v,id,z,c,dfn[z],end[ls[id]]);
        if(!u)u=++cnt;
        val[u]=val[v]+1,sum[u]=sum[v]+dis[c][z]-dis[c-1][z];
        if(id==z)return ls[u]=ls[v],rs[u]=rs[v],void();
        if(dfn[z]<=end[ls[id]])update(ls[u],ls[v],ls[id],z,c+(ls[id]<=n)),rs[u]=rs[v];
        else update(rs[u],rs[v],rs[id],z,c+(rs[id]<=n)),ls[u]=ls[v];
    }
    void dfs(cll u){
        //printf("%lld %lld %lld\n",u,ls[u],rs[u]);
        u<=n&&(dfn[u]=++top),
        ls[u]&&(dfs(ls[u]),0),
        u>n&&(dfn[u]=dfn[ls[u]]),
        rs[u]&&(dfs(rs[u]),0),
        end[u]=top;
    }
    ll root;
    void set(ll n_,const ll*a_){
        cnt=n=n_,root=build(1,n,1),dfs(root);
        memcpy(a,a_,(n+1)<<3);
        //rep(i,1,2)rep(j,1,n)printf("a[%lld][%lld]=%lld\n",i,j,dis[i][j]);
        //rep(i,1,cnt)printf("%lld %lld %lld %lld\n",ls[i],rs[i],dfn[i],end[i]);
        rep(i,1,n)update(rt[i],rt[i-1],root,a[i],1);
    }
    void calc(cll i){
        cll x=dfn[a[i]],y=dfn[a[i+1]],mx=x<y?y:x,mn=x<y?x:y;
        ll id=root,w=rt[i-1],u=rt[i],v=rt[i+1],c=0;
        for(;;){
            val[u]=val[w]+1,c+=(id<=n),
            sum[u]=sum[w]+dis[c][a[i+1]]-dis[c-1][a[i+1]];
            if(dfn[ls[id]]<=mn&&mx<=end[ls[id]])w=ls[w],u=ls[u],v=ls[v],id=ls[id];
            else if(dfn[rs[id]]<=mn&&mx<=end[rs[id]])w=rs[w],u=rs[u],v=rs[v],id=rs[id];
            else{
                ls[u]=ls[ls[u]==ls[w]?v:w],
                rs[u]=rs[rs[u]==rs[w]?v:w];
                break;
            }
        }
    }
    void change(cll u){
        calc(u),std::swap(a[u],a[u+1]);
    }
    ll query_pre(cll i,cll x)const{
        if(!i)return 0;
        ll res=0,u=rt[i],id=root,c=0;
        while(dfn[id]<=dfn[x]&&dfn[x]<=end[id]){
            if(id<=n)res-=val[u]*dis[c][x],res+=val[u]*dis[++c][x]+sum[u];//,printf("%lld %lld %lld\n",val[u],dis[c][x],sum[u]);
            if(x==id){
                //puts("???");
                break;
            }
            if(dfn[x]<=end[ls[id]])u=ls[u],id=ls[id];
            else u=rs[u],id=rs[id];
        }
        //printf("sum=%lld\n",res);
        return res;
    }
    ll query(cll l,cll r,cll x)const{
        return query_pre(r,x)-query_pre(l-1,x);
    }
}dt;
aN a;
int main(){
    rep(i,1,n)a[i]=readll();
    rep(i,2,n){
        cll u=readll(),v=readll(),w=readll();
        add(u,v,w),add(v,u,w);
    }
    dt.set(n,a);
    ll lstans=0;
    rep(i,1,q){
        lstans&=(1<<30)-1;
        if(readll()==1){
            cll l=readll()^lstans,r=readll()^lstans,x=readll()^lstans;
            writell(lstans=dt.query(l,r,x),10);
        }else dt.change(readll()^lstans);
    }
    return 0;
}
/*
19 16
17 3 12 2 13 1 15 14 5 11 7 10 16 19 9 18 4 8 6
5 1 496
6 3 247
13 5 973
7 10 794
6 12 145
4 6 232
8 4 499
11 8 114
11 14 644
2 11 348
16 2 901
16 15 978
9 18 807
17 9 910
16 17 268
7 16 152
13 7 869
13 19 990
1
3 18 6

1

38329 38335 38331

1

9575 9574 9593

2

1010

2

1005

2

1008

2

1010

2

1004

2

1022

2

1017

1

1023 1017 1020

1

9682 9685 9673

2

18247

1

18266 18247 18264

1

16835 16833 16859

1

4207 4200 4203

*/