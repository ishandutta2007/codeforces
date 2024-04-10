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
cll N=1e6+7,mod=998244353,iv2=(mod+1)/2,g=3,iz=1<<21,oz=1<<22;
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
cll IO_res=IO();
//cll n=10,m=100;
cll n=readll(),m=readll();
aN a,b,p,wA,wB;
std::mt19937_64 rd;
struct node{
    ll c,v;
    operator ll()const{
        return c;
    }
};
std::vector<node>A[N],B[N];
aN hA,hB,st;
ll t;
ll dfs(cll x,cll y){
    //writell(x),writell(y,10);
    if(hA[x]!=hB[y])return 0;
    if(wA[x]==y&&wB[y]==x)return 1;
    if(wA[x]||wB[y])return 0;
    wA[x]=y,wB[y]=x,st[++t]=x;
    cll up=A[x].size();
    ref(i,0,up)if(!dfs(A[x][i].v,B[y][i].v))return 0;
    return 1;
}
//ll sA[1001][1001],sB[1001][1001];
struct ans_t{
    ll p,x,y;
    void print()const{
        writell(p),writell(x),writell(y,10);
    }
    /*void calc()const{
        if(p==1)rep(j,1,m)std::swap(sA[x][j],sA[y][j]);
        else rep(i,1,n)std::swap(sA[i][x],sA[i][y]);
    }*/
}res[N];
int main(){
    rep(i,1,n*m)p[i]=rd()>>1;
    /*rep(z,1,n){
        static aN t;
        cll x=rand()%n+1,y=rand()%m+1;
        rep(i,1,n)t[sA[i][y]]=z;
        rep(j,1,m)t[sA[x][j]]=z;
        ll c=0,ct[n*m];
        rep(i,1,n*m)if(t[i]!=z)ct[c++]=i;
        if(c)sA[x][y]=ct[rand()%c];
    }
    memcpy(sB,sA,sizeof sA);
    rep(i,1,n*m){
        cll p=rand()%2+1,x=p==1?rand()%n+1:rand()%m+1,y=p==1?rand()%n+1:rand()%m+1;
        (ans_t){p,x,y}.calc();
    }*/
    rep(i,1,n)rep(j,1,m)if(cll c=readll())A[i].push_back((node){c,j+n}),A[j+n].push_back((node){c,i}),hA[i]^=p[c],hA[j+n]^=p[c];
    rep(i,1,n+m)std::sort(A[i].begin(),A[i].end());
    rep(i,1,n)rep(j,1,m)if(cll c=readll())B[i].push_back((node){c,j+n}),B[j+n].push_back((node){c,i}),hB[i]^=p[c],hB[j+n]^=p[c];
    rep(i,1,n+m)std::sort(B[i].begin(),B[i].end());
    cll l=n<m?1:n+1,r=n<m?n:n+m;
    rep(i,l,r)if(!wA[i]){
        ll flag=0;
        rep(j,l,r)if(!wB[j]&&hA[i]==hB[j]){
            t=0;
            ll c;
            if(!dfs(i,j))while(t)c=st[t--],wA[c]=wB[wA[c]]=0;
            else{
                flag=1;
                break;
            }
        }
        if(!flag)return!myputs("-1");
    }
    ll j=1;
    rep(i,1,n+m)if(!wA[i]){
        while(wB[j])j++;
        wA[i]=j,wB[j]=i;
    }
    //rep(i,1,n+m)writell(wA[i]),writell(wB[i],10);
    t=0;
    rep(i,1,n)while(wA[i]&&wA[i]<i)res[++t]=(ans_t){1,i,wA[i]},std::swap(wA[i],wA[wA[i]]);
    rep(i,n+1,n+m)while(wA[i]&&wA[i]<i)res[++t]=(ans_t){2,i-n,wA[i]-n},std::swap(wA[i],wA[wA[i]]);
    //rep(i,1,n)rep(j,1,m)writell(sA[i][j],j==m?10:32);
    //rep(i,1,n)rep(j,1,m)writell(sB[i][j],j==m?10:32);
    writell(t,10);
    rep(i,1,t)res[i].print();//,res[i].calc();
    //rep(i,1,n)rep(j,1,m)assert(sA[i][j]==sB[i][j]);
    return 0;
}