#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=600005;
const int ks=512;
const int maxl=20;

int n;
int a[maxn];

vector<int> adj[maxn];
int fa[maxn][maxl];
int seq[maxn],c1;
int st[maxn],ed[maxn];
int dep[maxn];
void dfs(int u){
    seq[++c1]=a[u];
    st[u]=c1;
    for(int v:adj[u]){
        if(v!=fa[u][0]){
            dep[v]=dep[u]+1;
            fa[v][0]=u;
            for(int i=1;i<maxl;i++)fa[v][i]=fa[fa[v][i-1]][i-1];
            dfs(v);
        }
    }
    seq[++c1]=a[u];
    ed[u]=c1;
}

int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    for(int i=maxl-1;i>=0;i--)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
    if(u==v)return u;
    for(int i=maxl-1;i>=0;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int q;

struct qry{
    int pl,pr,l,r,idx,e;
}qx[maxn];

int ocr[maxn];

int w[maxn],sum[maxn];
inline int qryx(int l,int r){
    int kl=l/ks,kr=r/ks;
    if(kl==kr){
        for(int i=l;i<=r;i++)if(w[i])return i;
        return -1;
    }else{
        for(int i=l;i/ks==l/ks;i++)if(w[i])return i;
        for(int i=r;i/ks==r/ks;i--)if(w[i])return i;
        for(int i=kl+1;i<kr;i++){
            if(sum[i]){
                for(int j=i*ks;j<(i+1)*ks;j++)if(w[j])return j;
            }
        }
        return -1;
    }
}

inline void chg(int x){
    ocr[x]^=1;
    if(ocr[x]){
        w[x]++;sum[x/ks]++;
    }else{
        w[x]--;sum[x/ks]--;
    }
}
int tans[maxn];
namespace nqio{const unsigned R=4e5,W=4e5;char*a,*b,i[R],o[W],*c=o,*d=o+W,h[40],*p=h,y;bool s;struct q{void r(char&x){x=a==b&&(b=(a=i)+fread(i,1,R,stdin),a==b)?-1:*a++;}void f(){fwrite(o,1,c-o,stdout);c=o;}~q(){f();}void w(char x){*c=x;if(++c==d)f();}q&operator>>(char&x){do r(x);while(x<=32);return*this;}q&operator>>(char*x){do r(*x);while(*x<=32);while(*x>32)r(*++x);*x=0;return*this;}template<typename t>q&operator>>(t&x){for(r(y),s=0;!isdigit(y);r(y))s|=y==45;if(s)for(x=0;isdigit(y);r(y))x=x*10-(y^48);else for(x=0;isdigit(y);r(y))x=x*10+(y^48);return*this;}q&operator<<(char x){w(x);return*this;}q&operator<<(char*x){while(*x)w(*x++);return*this;}q&operator<<(const char*x){while(*x)w(*x++);return*this;}template<typename t>q&operator<<(t x){if(!x)w(48);else if(x<0)for(w(45);x;x/=10)*p++=48|-(x%10);else for(;x;x/=10)*p++=48|x%10;while(p!=h)w(*--p);return*this;}}qio;}using nqio::qio;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    qio>>n>>q;
    for(int i=1;i<=n;i++)qio>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        qio>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[1]=1;
    dfs(1);
    for(int i=1;i<=q;i++){
        int u,v,l,r;
        qio>>u>>v>>qx[i].l>>qx[i].r;qx[i].idx=i;
        if(st[v]>=st[u]&&st[v]<=ed[u]){
            qx[i].pl=st[u];qx[i].pr=st[v];
        }else if(st[u]>=st[v]&&st[u]<=ed[v]){
            qx[i].pl=st[v];qx[i].pr=st[u];
        }else if(st[u]<st[v]){
            qx[i].pl=ed[u];qx[i].pr=st[v];
            qx[i].e=lca(u,v);
        }else{
            qx[i].pl=ed[v];qx[i].pr=st[u];
            qx[i].e=lca(u,v);
        }
    }
    cerr<<"?";
    sort(qx+1,qx+1+q,[](const qry&a,const qry&b){
        return (a.pl/ks==b.pl/ks?(((a.pl/ks)&1)?a.pr>b.pr:a.pr<b.pr):a.pl<b.pl);
    });
    int cl=1,cr=0;
    for(int i=1;i<=q;i++){
        int tl=qx[i].pl,tr=qx[i].pr;
        while(cr<tr){chg(seq[++cr]);}
        while(cl>tl){chg(seq[--cl]);}
        while(cr>tr){chg(seq[cr--]);}
        while(cl<tl){chg(seq[cl++]);}
        if(qx[i].e)chg(a[qx[i].e]);
        tans[qx[i].idx]=qryx(qx[i].l,qx[i].r);
        if(qx[i].e)chg(a[qx[i].e]);
    }
    for(int i=1;i<=q;i++)qio<<tans[i]<<'\n';
    return 0;
}