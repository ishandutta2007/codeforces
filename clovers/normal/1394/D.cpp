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
const ll INF=(ll)2e13;
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
const int N=200005;
#define int long long
int n,a[N],b[N],dp[N][2],top=0;
vector<int> v[N];
struct node{
    int a,b,val;
    bool operator < (const node &rhs) const{
        return val<rhs.val;
    }
}t[N];

int calc(int cnt0,int cnt1,int flag,int x){
    if(cnt0==cnt1) return cnt0+(x!=1);
    if(!flag){
        if(cnt0>cnt1) return cnt0;
        else return cnt1+(x!=1);
    }
    else{
        if(cnt1>cnt0) return cnt1;
        else return cnt0+(x!=1);
    }
}

void update(int x){
    for(int i=1;i<=top;i++) t[i].val=t[i].b-t[i].a;
    sort(t+1,t+top+1);
    int ret=0,cnt0=top,cnt1=0;
    for(int i=1;i<=top;i++) ret+=t[i].a;
    checkmin(dp[x][0],ret+calc(cnt0,cnt1,0,x)*a[x]);
    checkmin(dp[x][1],ret+calc(cnt0,cnt1,1,x)*a[x]);
    for(int i=1;i<=top;i++){
        cnt0--; cnt1++;
        ret+=t[i].val;
        checkmin(dp[x][0],ret+calc(cnt0,cnt1,0,x)*a[x]);
        checkmin(dp[x][1],ret+calc(cnt0,cnt1,1,x)*a[x]);
    }
}

void dfs(int u,int f){
    for(auto &to : v[u]) if(to!=f) dfs(to,u);
    top=0;
    for(auto &to : v[u]) if(to!=f){
        top++;
        t[top].a=(b[to]>b[u] ? INF : dp[to][0]);
        t[top].b=(b[to]<b[u] ? INF : dp[to][1]);
    }
    update(u);
}

signed main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2;j++) dp[i][j]=INF;
    }
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    dfs(1,-1);
    int ans=min(dp[1][0],dp[1][1]);
    cout<<ans<<endl;
    return 0;
}