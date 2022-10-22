#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=2e5+7,mod=1e9+7,iz=1<<21,oz=1<<22;
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
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10+48;
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
char s[N];
aN que,ans,end,dfn,next,to,head,len,sta,a;
ll cnt,top;
struct block{
    aN f1,f2;
    ll n,b,m;
    void set(cll n_,cll b_){
        n=n_,b=b_,m=n/b;
    }
    void update(cll u,cll c){
        //printf("dt[%lld]+=%lld\n",u,c);
        cll id=u/b,l=id*b;
        rep(i,l,u)f1[i]+=c;
        rep(i,0,id-1)f2[i]+=c;
    }
    ll query(cll u)const{
        //printf("dt[1-%lld]=%lld\n",u,f1[u]+f2[u/b]);
        return f1[u]+f2[u/b];
    }
}dt;
void add(cll u,cll v){
    //printf("%lld %lld\n",u,v);
    next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs0(cll u){
    dfn[u]=++top;
    rev(i,u,v)dfs0(v);
    end[u]=top;
}
void dfs2(cll u){
    rev(i,u,v)dfs2(v),a[u]+=a[v];
}
struct qu{
    ll w,x,id;
}q[N];
int cmpw(const qu&a,const qu&b){
    return a.w<b.w;
}
int cmpx(const qu&a,const qu&b){
    return a.x==b.x?a.w<b.w:a.x<b.x;
}
aN son[26],pos,fail;
int main(){
    IO();
    //gc=getchar;
    cll n=readll(),m=readll(),B=sqrt(n);
    ll cnt=1;
    char*s=::s;
    rep(i,1,n){
        cll m=len[i]=mygets(s+1);
        sta[i+1]=sta[i]+m;
        ll now=1;
        rep(j,1,m)now=son[s[j]-97][now]?:son[s[j]-97][now]=++cnt;
        pos[i]=now,s+=m;
    }
    ll t=que[1]=1;
    rep(c,0,25)son[c][0]=1;
    rep(h,1,t){
        cll i=que[h];
        rep(c,0,25)if(son[c][i])fail[que[++t]=son[c][i]]=son[c][fail[i]];
        else son[c][i]=son[c][fail[i]];
        add(fail[i],i);
    }
    dfs0(1);
    ll tq=0;
    rep(i,1,m){
        cll l=readll(),r=readll(),x=readll();
        q[++tq]=(qu){r,x,i};
        if(l>1)q[++tq]=(qu){l-1,x,i+m};
    }
    std::sort(q+1,q+tq+1,cmpx);
    ll p=1;
    rep(i,1,n)if(len[i]>=B){
        while(p<=tq&&q[p].x<i)p++;
        if(q[p].x!=i)continue;
        char*s=::s+sta[i];
        memset(a+1,0,cnt<<3);
        ll now=1,l=len[i];
        rep(i,1,l)a[now=son[s[i]-97][now]]++;
        dfs2(1);
        ll sum=0;
        rep(j,1,n){
            if(q[p].x!=i)break;
            sum+=a[pos[j]];
            while(p<=tq&&q[p].x==i&&q[p].w==j)ans[q[p].id]+=sum,p++;
            
        }
    }
    std::sort(q+1,q+tq+1,cmpw);
    p=1;
    dt.set(cnt,sqrt(cnt));
    rep(i,1,n){
        dt.update(end[pos[i]],1),dt.update(dfn[pos[i]]-1,-1);
        while(p<=tq&&q[p].w==i){
            if(len[q[p].x]<B){
                ll sum=0,i=q[p].x;
                char*s=::s+sta[i];
                ll now=1,l=len[i];
                rep(i,1,l)sum+=dt.query(dfn[now=son[s[i]-97][now]]);
                ans[q[p].id]+=sum;
            }
            p++;
        }
    }
    rep(i,1,m)writell(ans[i]-ans[i+m],10);
    return 0;
}
/*
5 5
a
ab
abab
ababab
b
1 5 4
3 5 4
1 5 2
1 5 3
1 4 1
*/