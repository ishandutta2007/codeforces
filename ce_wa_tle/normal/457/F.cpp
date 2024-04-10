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
static inline ll max(cll a,cll b){
    return a<b?b:a;
}
static inline void qmax(ll&a,cll b){
    a<b&&(a=b);
}
static inline ll min(cll a,cll b){
    return a<b?a:b;
}
aN step,l,r,a;
ll f[N][2][3];
void dfs0(cll u){
    if(!l[u]){step[u]=0;return;}
    dfs0(l[u]),dfs0(r[u]);
    if(step[r[u]]&1)std::swap(l[u],r[u]);
    step[u]=step[l[u]]+step[r[u]]+1;
}
ll dfs2(cll u,cll w,cll s){
    cll ls=l[u],rs=r[u];
    if(!ls)return w?-a[u]:a[u];
    if(step[u]==1)return s==2?min(dfs2(ls,w,0),dfs2(rs,w,0)):max(dfs2(ls,w,0),dfs2(rs,w,0));
    if(f[u][w][s])return f[u][w][s];
    cll type=(step[ls]&1)+(step[rs]&1);
    ll ans=0;
    if(!s){
        switch(type){
            case 0:ans=max(dfs2(ls,w,0),dfs2(rs,w,0));break;
            case 1:ans=max(min(dfs2(ls,w,0),-dfs2(rs,!w,0)),min(dfs2(rs,w,1),-dfs2(ls,!w,1)));break;
            case 2:ans=max(dfs2(ls,w,1),dfs2(rs,w,1));break;
        }
        return f[u][w][s]=ans;
    }
    cll rm=s==1&&step[rs]<=1?2:1,lm=s==1&&step[ls]<=1?2:1;
    switch(type){
        case 0:ans=max(min(dfs2(ls,w,rm),-dfs2(rs,!w,0)),min(dfs2(rs,w,lm),-dfs2(ls,!w,0)));break;
        case 1:ans=max(dfs2(ls,w,rm),dfs2(rs,w,0));break;
        case 2:ans=max(step[ls]?min(dfs2(ls,w,0),-dfs2(rs,!w,lm)):-mod,step[rs]?min(dfs2(rs,w,0),-dfs2(ls,!w,rm)):-mod);break;
    }
    return f[u][w][s]=max(ans,-dfs2(u,!w,0));
}
int main(){
    IO();
    //gc=getchar;
    //pc=putchar;
    cll T=readll();
    rep(i,1,T){
        cll n=readll();
        memset(f,0,sizeof(f[0])*(n+1));
        ref(i,0,n){
            cll f=readll();
            if(f==-1)l[i]=readll(),r[i]=readll();
            else a[i]=f+1,l[i]=r[i]=0;
        }
        dfs0(0);
        writell(dfs2(0,0,0)-1,10);
    }
    return 0;
}
/*
1
7
-1 1 2
-1 3 4
997
-1 5 6
550
492
275
*/
/*
4

3
-1 1 2
10
5

5
-1 1 2
-1 3 4
10
5
20

7
-1 1 2
-1 3 4
-1 5 6
1
2
3
4

11
-1 1 2
-1 3 4
-1 5 6
-1 7 8
15
7
-1 9 10
7
8
9
11

*/
/*
1
29
-1 1 2
-1 3 4
-1 7 8
-1 5 6
840
-1 13 14
745
-1 15 16
-1 9 10
-1 21 22
-1 11 12
73
-1 25 26
486
182
-1 23 24
-1 17 18
547
-1 19 20
881
196
294
791
839
174
654
-1 27 28
757
117
*/