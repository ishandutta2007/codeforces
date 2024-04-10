/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
#define y1 jzybuxing
#define y2 jzyshabi
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=600005;
int n; vector<int> v[N];
char s[N],t[N];
struct SA{
    int sa[N],rk[N],id[N],oldrk[N<<1],cnt[N],P[N];
    int h[N];
    bool cmp(int x,int y,int w){
        return oldrk[x]==oldrk[y]&&oldrk[x+w]==oldrk[y+w];
    }
    void build(){
        n*=2;
        int m=130,p;
        for(int i=1;i<=n;i++) ++cnt[rk[i]=s[i]];
        for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
        for(int i=n;i>=1;i--) sa[cnt[rk[i]]--]=i;
        for(int w=1;w<n;w<<=1,m=p){
            p=0;
            for(int i=n;i>n-w;i--) id[++p]=i;
            for(int i=1;i<=n;i++) if(sa[i]>w) id[++p]=sa[i]-w;
            memset(cnt,0,sizeof(int)*(m+1));
            for(int i=1;i<=n;i++) ++cnt[P[i]=rk[id[i]]];
            for(int i=1;i<=m;i++) cnt[i]+=cnt[i-1];
            for(int i=n;i>=1;i--) sa[cnt[P[i]]--]=id[i];
            memcpy(oldrk,rk,sizeof(int)*(n+1));
            p=0;
            for(int i=1;i<=n;i++){
                rk[sa[i]]=(cmp(sa[i],sa[i-1],w) ? p : ++p);
            }
            if(p==n) break;
        }
    }
    int st[N][20],lg[N];
    int query(int l,int r){
        int sz=r-l+1;
        return min(st[l][lg[sz]],st[r-(1<<lg[sz])+1][lg[sz]]);
    }
    void buildh(){
        int k=0;
        for(int i=1;i<=n;i++){
            if(k) k--;
            while(s[i+k]==s[sa[rk[i]-1]+k]) k++;
            h[rk[i]]=k;
        }
        for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
        for(int i=1;i<=n;i++) st[i][0]=h[i];
        for(int j=1;j<20;j++){
            for(int i=1;i<=n;i++){
                if(i+(1<<j)-1>n) break;
                int to=i+(1<<(j-1));
                st[i][j]=min(st[i][j-1],st[to][j-1]);
            }
        }
    }
    int LCP(int x,int y){
        if(x==y) return inf;
        if(rk[x]>rk[y]) swap(x,y);
        return query(rk[x]+1,rk[y]);
    }
}S;

int son[N],top[N],sz[N],dfn[N],id[N],dep[N],fa[N],dfn_clock=0;
void dfs1(int u){
    sz[u]=1;
    for(auto &to : v[u]){
        if(to==fa[u]) continue;
        fa[to]=u; dep[to]=dep[u]+1; dfs1(to);
        sz[u]+=sz[to]; 
        if(sz[son[u]]<sz[to]) son[u]=to;
    }
}

void dfs2(int u){
    dfn[u]=++dfn_clock; id[dfn_clock]=u;
    if(son[u]) top[son[u]]=top[u],dfs2(son[u]);
    for(auto &to : v[u]){
        if(to==fa[u]||to==son[u]) continue;
        top[to]=to; dfs2(to);
    }
}
int LCA(int x,int y){
    while(top[x]!=top[y]){
        if(dep[top[x]]>dep[top[y]]) x=fa[top[x]];
        else y=fa[top[y]];
    }
    return dep[x]<dep[y] ? x : y;
}

void split(int x,int y,vector<pii> &seq){
    seq.clear();
    int lca=LCA(x,y);
    vector<pii> v1; v1.clear();
    while(top[x]!=top[lca]){
        int to=top[x],u=fa[to];
        seq.push_back(mk(2*n+1-dfn[x],2*n+1-dfn[to]));
        x=u;
    }
    seq.push_back(mk(2*n+1-dfn[x],2*n+1-dfn[lca]));
    while(top[y]!=top[lca]){
        int to=top[y],u=fa[to];
        v1.push_back(mk(dfn[to],dfn[y]));
        y=u;
    }
    if(y!=lca) v1.push_back(mk(dfn[lca]+1,dfn[y]));
    reverse(v1.begin(),v1.end());
    for(auto &u : v1) seq.push_back(u);
}

void init(){
    n=read();
    scanf("%s",t+1);
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    dep[1]=0; dfs1(1);
    top[1]=1; dfs2(1);
    for(int i=1;i<=n;i++) s[dfn[i]]=t[i];
    for(int i=n+1;i<=n+n;i++) s[i]=s[2*n+1-i];
    S.build(); S.buildh(); n/=2;
}

vector<pii> v1,v2;
void solve(){
    int m=read();
    while(m--){
        int x1=read(),y1=read(),x2=read(),y2=read();
        split(x1,y1,v1); split(x2,y2,v2);
        int i1=0,i2=0,j1=v1[0].first,j2=v2[0].first;
        int ret=0;
        while(i1<sz(v1)&&i2<sz(v2)){
            int len=S.LCP(j1,j2);
            checkmin(len,min(v1[i1].second-j1+1,v2[i2].second-j2+1));
            ret+=len;
            j1+=len; j2+=len;
            if(j1<=v1[i1].second&&j2<=v2[i2].second) break;
            if(j1>v1[i1].second){
                i1++; if(i1==sz(v1)) break;
                j1=v1[i1].first;
            }
            if(j2>v2[i2].second){
                i2++; if(i2==sz(v2)) break;
                j2=v2[i2].first;
            }
        }
        printf("%d\n",ret);
    }
}

int main()
{
    init(); solve();
    return 0;
}