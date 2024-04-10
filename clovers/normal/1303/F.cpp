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
const int N=305;
struct Query{
    int x,y,c,id;
}Q[2000005];
int C[2000005];
vector<Query> v[2000001];
int ans[2000005],T[2000005];
int q,n,m,a[N][N],b[N][N],lst[2000001];
int num=0,cnt=0,vis[N][N];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
pii tmp[N*N];
int idx(int x,int y){return (x-1)*m+y;}
struct DSU{
    int ID;
    vector<int> fa;
    int tot=0;
    void init(int x){ID=x; fa.resize(1); tot=0;}
    int Newnode(int x){
        if(tmp[x].first==ID) return tmp[x].second;
        tmp[x]=mk(ID,++tot); fa.push_back(tot);
        return tot;
    }
    int getfather(int x){
        return x==fa[x] ? x : fa[x]=getfather(fa[x]);
    }
    void unite(int x,int y){
        x=getfather(x); y=getfather(y);
        if(x==y) return;
        cnt--; fa[x]=y;
    }
};
vector<DSU> D;
void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int xx=dx[i]+x,yy=dy[i]+y;
        if(xx<1||yy<1||xx>n||yy>m||a[xx][yy]!=a[x][y]||vis[xx][yy]) continue;
        dfs(xx,yy); 
        int from=D[a[x][y]].Newnode(idx(x,y));
        int to=D[a[x][y]].Newnode(idx(xx,yy));
        D[a[x][y]].unite(from,to);
    }
}

int main()
{
    int mx=0;
    n=read(); m=read(); q=read();
    for(int i=1;i<=q;i++){
        int x=read(),y=read(),c=read();
        C[i]=c;
        v[c].push_back({x,y,c,i});
        Q[i].x=x; Q[i].y=y; Q[i].c=a[x][y];
        a[x][y]=c; checkmax(mx,c);
        lst[c]=i;
    }
    for(int i=1;i<=n*m;i++) tmp[i]=mk(-1,-1);
    D.resize(mx+1);
    for(int i=0;i<=mx;i++) D[i].init(i);
    for(int i=1;i<=mx;i++){
        cnt=0;
        for(auto &u : v[i]){
            int x=u.x,y=u.y;
            if(b[x][y]==i){
                T[u.id]=cnt;
                continue;
            }
            cnt++; b[x][y]=i;
            for(int j=0;j<4;j++){
                int xx=x+dx[j],yy=y+dy[j];
                if(xx<1||yy<1||xx>n||yy>m||b[xx][yy]!=b[x][y]) continue;
                int from=D[i].Newnode(idx(x,y));
                int to=D[i].Newnode(idx(xx,yy));
                D[i].unite(from,to);
            }
            T[u.id]=cnt;
        }
    }
    for(int i=1;i<=n*m;i++) tmp[i]=mk(-1,-1);
    for(int i=0;i<=mx;i++) D[i].init(i);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) if(!vis[i][j]){
            dfs(i,j); num++;
        }
    }
    cnt=num;
    for(int i=q;i>=1;i--){
        if(i==lst[C[i]]) cnt-=T[i];
        ans[i]=cnt+T[i];
        int x=Q[i].x,y=Q[i].y,c=Q[i].c;
        if(c==a[x][y]) continue;
        a[x][y]=c; cnt++;
        for(int j=0;j<4;j++){
            int xx=x+dx[j],yy=y+dy[j];
            if(xx<1||yy<1||xx>n||yy>m||a[xx][yy]!=a[x][y]) continue;
            int from=D[c].Newnode(idx(x,y));
            int to=D[c].Newnode(idx(xx,yy));
            D[c].unite(from,to);
        }
    } 
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}