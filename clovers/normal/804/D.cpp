/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
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
const int N=100005;
double ans[N];
int n,m,q,bel[N],top=0,dep[N],dis[N],len[N],mxdep=0,mxid;
vector<int> seq[N],v[N];
void dfs(int u,int f,int k){
    if(k!=-1) seq[k].push_back(u),bel[u]=k;
    if(mxdep<dep[u]) mxdep=dep[u],mxid=u;
    for(auto &to : v[u]) if(to!=f){
        dep[to]=dep[u]+1; dfs(to,u,k);
    }
}
map<pii,double> mp;
vector<double> sum[N],P[N];

int main()
{
    n=read(); m=read(); q=read();
    for(int i=1;i<=m;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    for(int i=1;i<=n;i++) if(!bel[i]){
        mxdep=-1; mxid;
        bel[i]=++top; dfs(i,-1,top);
        mxdep=-1; int pos1=mxid; dep[mxid]=0; 
        dfs(mxid,-1,-1);
        int pos2=mxid; 
        len[top]=mxdep; 
        for(auto &u : seq[top]) dis[u]=dep[u];
        dep[pos2]=0; 
        dfs(pos2,-1,-1);
        for(auto &u : seq[top]) checkmax(dis[u],dep[u]); 
        sum[top].resize(len[top]+2); P[top].resize(len[top]+1);
        for(auto &u : seq[top]) P[top][dis[u]]+=1.0/sz(seq[top]);
        for(int j=len[top];j>=0;j--) sum[top][j]=P[top][j]+sum[top][j+1];
        for(int j=len[top];j>=0;j--) sum[top][j]+=sum[top][j+1];
    }
    // for(int i=1;i<=top;i++){
    //     out(i),outln(len[i]);
    //     for(auto &u : seq[i]) out(u),outln(dis[u]);
    //     for(int j=0;j<=len[i];j++) cout<<P[i][j]<<" "; cout<<endl;
    //     puts("");
    // }
    while(q--){
        int x=read(),y=read();
        x=bel[x]; y=bel[y];
        if(x==y){puts("-1"); continue;}
        if(mp.count(mk(x,y))){
            printf("%.8lf\n",mp[mk(x,y)]);
            continue;
        }
        if(len[x]<len[y]) swap(x,y);
        double ret=len[x];
        for(int i=0;i<=len[y];i++){
            // out(i); out(P[y][i]); outln(sum[x][len[x]-i]);
            ret+=P[y][i]*sum[x][len[x]-i];
        }
        printf("%.8lf\n",mp[mk(x,y)]=ret);
    }
    return 0;
}