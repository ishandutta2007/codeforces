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
cll N=1111,mod=1e9+7,iz=1<<21,oz=1<<22;
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
cll IO_res=IO(),T=readll();
aN f,hf[111],hs,fa,is_leaf,head,to,next,vis,dis[111],a[111][111];
ll find(cll u){
    return u^f[u]?f[u]=find(f[u]):u;
}
ll is_tree,cnt_tree,cnt=0; 
void add(cll u,cll v){
    //printf("%lld %lld\n",u,v);
    if(find(u)==find(v))is_tree=0;
    cnt_tree++,f[find(u)]=find(v);
    next[++cnt]=head[u],to[head[u]=cnt]=v;
    next[++cnt]=head[v],to[head[v]=cnt]=u;
}
void dfs(cll s,cll u,cll fa){
    rev(i,u,v)if(v^fa)dis[s][v]=dis[s][u]+1,dfs(s,v,u);
}
void calc(){
    cll n=readll();
    memset(head,cnt=0,(n+1)<<3);
    memset(fa,0,(n+1)<<3);
    rep(i,1,n)rep(j,i+1,n)rep(k,1,n)a[i][j][k]=readchar()^48;
    /*{
        rep(i,2,n){
            cll u=i,v=rand()%(i-1)+1;
            add(u,v);
            //printf("%lld %lld\n",u,v);
        }
        rep(i,1,n)dfs(i,i,0);
        rep(i,1,n)rep(j,i+1,n)rep(k,1,n)a[i][j][k]=dis[i][k]==dis[j][k];
        memset(head,cnt=0,(n+1)<<3);
    }*/
    ll l=0,m=n;
    rep(k,1,n){
        rep(i,1,n)f[i]=i,vis[i]=0;
        rep(i,1,n)rep(j,i+1,n)if(a[i][j][k])f[find(i)]=find(j);
        else if(find(i)==find(j))return myputs("No"),void();
        ll s=0;
        rep(i,1,n)hf[k][i]=find(i),!vis[find(i)]&&(vis[find(i)]=1,s++);
        hs[k]=s,l=std::max(l,s),m=std::min(m,s);
    }
    rep(i,1,n)f[i]=i;//,printf("%lld\n",hs[i]);
    is_tree=1,cnt_tree=0;
    {
        ll f=0,l=0;
        rep(i,1,n)if(hs[i]==m)f?l=i:f=i;
        if(l)add(f,l),fa[f]=l,fa[l]=f;
    }
    rep(d,m,l-1){
        rep(i,1,n)if(hs[i]==d){
            //printf("i=%lld\n",i);
            ll has[n+1]={},has2[n+1]={},size[n+1]={};
            rep(j,1,n)if(hs[j]<=d+1){
                size[hf[i][j]]++;
                if(j==fa[i])has[hf[i][j]]=1;
                if(hs[j]==d+1)has2[hf[i][j]]=1;
            }
            ll flag=0;
            rep(k,1,n)if(size[k]&&has[k]&&has2[k]){
                rep(j,1,n)if(hs[j]==d+1&&hf[i][j]==k)fa[j]=i,add(i,j);
                flag=1;break;
            }
            if(flag==0&&d==m){
                rep(k,1,n)if(size[k]&&has2[k]){
                    rep(j,1,n)if(hs[j]==d+1&&hf[i][j]==k)fa[j]=i,add(i,j);
                    break;
                }
            }
        }
    }
    if(!is_tree||cnt_tree!=n-1)return myputs("No"),void();
    rep(i,1,n)dfs(i,i,0);
    rep(i,1,n)rep(j,i+1,n)rep(k,1,n)if(a[i][j][k]!=(dis[i][k]==dis[j][k]))return myputs("No"),void();
    myputs("Yes");
    rep(u,1,n)rev(i,u,v)if(i&1)writell(u),writell(v,10);
}
int main(){
    rep(i,1,T)calc(); 
    return 0;
}
/*
1
3
001 000
000


5
5
00000 01001 00000 01100
00000 10000 00000
00000 11010
00000
2
00
2
10
3
001 000
000
3
001 010
000


1
4

*/