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
const ll INF=(ll)2e18;
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
const int N=1505;
int n,m,a[N][N],b[N][N];
vector<int> ans;
vector<int> v[N];
map<vector<int>,int> mp,mp2;
int from[N],deg[N],bl[N],vis[N];
bool check(){
    for(auto &u : ans) vis[u]=1;
    for(int i=1;i<n;i++) if(from[i]>from[i+1]){
        int flag=0;
        for(int j=1;j<=m;j++) if(vis[j]&&b[i][j]<b[i+1][j]) flag=1;
        if(!flag) return 0; 
    }
    return 1;
}

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++){
        vector<int> seq;
        for(int j=1;j<=m;j++) a[i][j]=read(),seq.push_back(a[i][j]);
        mp[seq]=i; mp2[seq]++;
    }
    for(int i=1;i<=n;i++){
        vector<int> seq;
        for(int j=1;j<=m;j++) b[i][j]=read(),seq.push_back(b[i][j]);
        if(!mp.count(seq)){puts("-1"); return 0;}
        from[i]=mp[seq];
        if(mp2[seq]==0){puts("-1"); return 0;}
        mp2[seq]--;
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<n;i++) if(b[i][j]>b[i+1][j]) 
            bl[i]=1,deg[j]++,v[i].push_back(j);
    }
    queue<int> q;
    for(int i=1;i<=m;i++) if(!deg[i]) q.push(i);
    while(!q.empty()){
        int u=q.front(); q.pop();
        ans.push_back(u);
        for(int i=1;i<n;i++) if(bl[i]&&b[i][u]<b[i+1][u]){
            bl[i]=0;
            for(auto &to : v[i]){
                if(!--deg[to]) q.push(to);
            }
        }
    }
    reverse(ans.begin(),ans.end());
    if(!check()) puts("-1");
    else{
        cout<<sz(ans)<<endl;
        for(auto &u : ans) printf("%d ",u);
    }
    return 0;
}