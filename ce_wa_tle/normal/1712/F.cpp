#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;n;i>>=1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef int ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=2e6+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
int myputs(const char*t,int c=10){
    const char*s=t;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
cll IO_res=IO(),T=1;
cll sz_ll=2;
aN next,to,head,d,p,q;
ll cnt;
void add(cll u,cll v){
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
/*std::vector<ll>tos[N];
void add(cll u,cll v){
    if(cnt==0){
        cnt=1;
        rep(i,1,1000000)tos[i].clear();
    }
    tos[u].push_back(v),tos[v].push_back(v);
}
#define rev(i,u,v)rfor(ll i=0,v;i!=(ll)tos[u].size()&&(v=tos[u][i]);i++)*/
aN ans,res;
struct node{
    ll p,dis;
    void calc(const node&m)const{
        //printf("%lld %lld %lld %lld\n",p,dis,m.p,m.dis);
        ans[p+m.p]=std::max(ans[p+m.p],dis+m.dis);
    }
    operator ll()const{
        return-p;
    }
    ll y()const{
        return p+dis;
    }
};
struct list{
    std::vector<node>se;
    /*void print()const{
        ref(i,0,(ll)se.size())printf("(%lld,%lld)\n",se[i].p,se[i].dis);
        puts("");
    }*/
    void swap(list&b){
        se.swap(b.se);
    }
    void merge(const list&a,const list&b){
        cll n=a.se.size(),m=b.se.size();
        ref(i,0,n)ref(j,0,m)a.se[i].calc(b.se[j]);
        node s[n+m];
        ll t=0,max=-1,j=0;
        ref(i,0,n){
            while(j<m&&b.se[j].p>=a.se[i].p){
                const node&now=b.se[j];
                if(now.y()>max){
                    if(t&&s[t-1].p==now.p)--t;
                    s[t++]=now,max=now.y();
                }
                j++;
            }
            const node&now=a.se[i];
            if(now.y()>max){
                if(t&&s[t-1].p==now.p)--t;
                s[t++]=now,max=now.y();
            }
        }
        while(j<m){
            const node&now=b.se[j];
            if(now.y()>max){
                if(t&&s[t-1].p==now.p)--t;
                s[t++]=now,max=now.y();
            }
            j++;
        }
        std::vector<node>(s,s+t).swap(se);
        //assert(se.size()<=3);
    }
};
aN vis,sz;
ll cmt=0;
ll findroot(cll u,list&res){
    static aN dis,lst,f,fa;
    static ll cnt=0;
    static node s[N];
    ++cnt,lst[u]=cnt,dis[u]=1;
    ll t=1,l=p[u],r=p[u];
    f[p[u]]=dis[u],q[1]=u;
    //cmt-=clock();
    rep(h,1,t){
        cll u=q[h];
        sz[u]=1;
        //printf("p = %lld %lld\n",u,p[u]);
        if(p[u]>r)f[++r]=dis[u];//,assert(r==p[u]);
        else if(p[u]<l)f[--l]=dis[u];//,assert(l==p[u]);
        else f[p[u]]=std::max(f[p[u]],dis[u]);
        rev(i,u,v)if(!vis[v]&&lst[v]!=cnt)fa[v]=u,lst[v]=cnt,dis[q[++t]=v]=dis[u]+1;
    }
    //cmt+=clock();
    ll max=-1,ts=0;
    per(i,r,l)if(i+f[i]>max)max=i+f[i],s[ts++]=(node){i,f[i]};
    //printf("%lld %lld %lld %lld\n",u,ts,l,r);
    std::vector<node>(s,s+ts).swap(res.se);
    //res.print();
    per(i,t,1){
        cll u=q[i];
        sz[fa[u]]+=sz[u];
        if(sz[u]*2>t)return u;
    }
    __builtin_unreachable();
}
void dfs(cll u,cll fa){
    //cmt+=sz[u];
    //printf("dfs %lld %lld\n",u,fa);
    static_cast<void>(fa);
    ll t=0;
    std::vector<list>p[(ll)sqrtl(sz[u])*3];
    vis[u]=1;
    list res;
    rev(i,u,v)if(!vis[v]){
        dfs(findroot(v,res),u);
        cll sz=res.se.size();
        //printf("%lld %lld\n",sz,::sz[u]);
        p[sz].push_back((list){});
        p[sz][p[sz].size()-1].swap(res);
        t++;
    }
    if(t){
        //printf("u = %lld t = %lld\n",u,t);
        p[1].push_back((list){});
        p[1][p[1].size()-1].se.push_back((node){::p[u],0});
        ll now=1;
        while(!p[now].size())now++;
        list min;
        min.swap(p[now].back()),p[now].pop_back();
        rep(i,1,t){
        //ref(i,0,3)writell(p[i].size(),i==2?10:32);
            while(!p[now].size())now++;
            min.merge(min,p[now].back()),p[now].pop_back();
            if(i==t)break;
            while(!p[now].size())now++;
            if((ll)min.se.size()>now){
                cll sz=min.se.size();
                p[sz].push_back((list){});
                p[sz][p[sz].size()-1].swap(min);
                min.swap(p[now].back()),p[now].pop_back();
            }
        }
    }
}
std::mt19937 rd;
void calc(){
    //cll n=10;
    cll n=readll();
    memset(vis,0,(n+1)<<sz_ll);
    memset(head,cnt=0,(n+1)<<sz_ll);
    memset(res,0,(n+1)<<sz_ll);
    memset(d,0,(n+1)<<sz_ll);
    rep(i,2,n){
        //cll u=i,v=rd()%(i-1)+1;
        cll u=i,v=readll();
        add(u,v),add(v,u),d[u]++,d[v]++;
    }
    ll t=0;
    memset(p,-1,(n+1)<<sz_ll);
    rep(i,1,n)if(d[i]<=1)p[q[++t]=i]=0;
    rep(h,1,t){
        cll u=q[h];
        //printf("%lld %lld\n",u,h);
        rev(i,u,v)if(!~p[v])p[q[++t]=v]=p[u]+1;
    }
    //rep(i,1,n)if(p[i]==-1)exit(0);
    memset(ans,-0x3f,(n+2)<<sz_ll);
    list now;
    cmt=0;
    //ll lst=clock();
    //ll sum=0;
    //rep(i,1,10000000)sum+=d[rd()%n];
    dfs(findroot(1,now),0);
    //fprintf(stderr,"n = %d cmt = %Lf %Lfs\n",n,cmt*1.L/CLOCKS_PER_SEC,(clock()-lst)*1.L/CLOCKS_PER_SEC);
    /*static aN ans2;
    memset(ans2,-0x3f,(n+2)<<sz_ll);
    rep(i,1,n){
        static aN dis;
        memset(dis,-1,(n+1)<<sz_ll);
        ll t=1;
        q[1]=i,dis[i]=0;
        rep(h,1,t){
            cll u=q[h];
            rev(i,u,v)if(!~dis[v])dis[q[++t]=v]=dis[u]+1;
            if(i!=u)ans2[p[i]+p[u]]=std::max(ans2[p[i]+p[u]],dis[u]);
        }
    }*/
    per(i,n,0)ans[i]=std::max(ans[i+1]+1,ans[i]),res[std::max((ll)0,ans[i]-i)]=ans[i];
    //per(i,n,0)ans2[i]=std::max(ans2[i+1]+1,ans2[i]);
    //rep(i,0,10)printf("%d\n",ans[i]);
    //rep(i,0,10)printf("%d\n",ans2[i]);
    //rep(i,0,n)assert(ans[i]==ans2[i]);
    //rep(i,0,10)printf("%lld\n",res[i]);
    rep(i,1,n)res[i]=std::max(res[i-1],res[i]);
    per(i,n,1)res[i]=std::max(res[i+1]-1,res[i]);
    cll q=readll();
    rep(i,1,q)writell(res[readll()],i==q?10:32);
}
int main(){
    rep(i,1,T)calc();
    return 0;
}
/*
7
1 2 3 4 2 1
7
2 1 3 7 5 6 4

*/