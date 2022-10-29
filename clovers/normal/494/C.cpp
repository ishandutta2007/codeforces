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
const int M=5005;
struct node{
    int l,r; double p;
}q[N];
int n,m,a[N],top=0,Max=0;
double dp[M][M<<1];
const int B=5001;
map<pii,int> mp; pii seq[N]; vector<double> P[N];
struct ST{
    int st[N][20],lg[N];
    int query(int l,int r){
        int sz=r-l+1;
        return max(st[l][lg[sz]],st[r-(1<<lg[sz])+1][lg[sz]]);
    }
    void init(){
        for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
        for(int i=1;i<=n;i++) st[i][0]=a[i];
        for(int j=1;j<20;j++){
            for(int i=1;i<=n;i++){
                if(i+(1<<j)-1>n) break;
                int to=i+(1<<(j-1));
                st[i][j]=max(st[i][j-1],st[to][j-1]);
            }
        }
    }
}T;
vector<int> v[M];
double sum1[M<<1],sum2[M<<1];
void dfs(int u){
    for(auto &to : v[u]){
        dfs(to);
        if(to==v[u][0]){
            for(int i=0;i<=B+m;i++) dp[u][i]=dp[to][i];
            continue;
        }
        sum1[0]=dp[u][0]; sum2[0]=dp[to][0];
        for(int i=1;i<=B+m;i++){
            sum1[i]=sum1[i-1]+dp[u][i];
            sum2[i]=sum2[i-1]+dp[to][i];
        }
        dp[u][0]=dp[u][0]*dp[to][0];
        for(int i=1;i<=B+m;i++){
            dp[u][i]=sum1[i-1]*dp[to][i]+sum2[i-1]*dp[u][i]+dp[u][i]*dp[to][i];
        }
    }
    int mx=T.query(seq[u].first,seq[u].second);
    int pos=(Max-mx<=B ? mx-Max+B : 0);
    double S=0;
    for(int i=0;i<pos;i++) S+=dp[u][i],dp[u][i]=0;
    dp[u][pos]+=S;
    if(v[u].empty()) dp[u][pos]=1;
    for(auto &p : P[u]){
        for(int i=B+m-1;i>=0;i--) dp[u][i+1]+=dp[u][i]*p,dp[u][i]*=(1-p);
    }
}

bool isfa(pii A,pii B){return A.first<=B.first&&A.second>=B.second;}
int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read(),checkmax(Max,a[i]);
    for(int i=1;i<=m;i++){
        scanf("%d%d%lf",&q[i].l,&q[i].r,&q[i].p);
        if(!mp.count(mk(q[i].l,q[i].r))){
            mp[mk(q[i].l,q[i].r)]=++top;
            seq[top]=mk(q[i].l,q[i].r);
        }
        int id=mp[mk(q[i].l,q[i].r)];
        P[id].push_back(q[i].p);
    }
    if(!mp.count(mk(1,n))) mp[mk(1,n)]=++top,seq[top]=mk(1,n);
    T.init();
    for(int i=1;i<=top;i++){
        int Fa=0;
        for(int j=1;j<=top;j++) if(i!=j&&isfa(seq[j],seq[i])){
            if(!Fa) Fa=j;
            else if(isfa(seq[Fa],seq[j])) Fa=j;
        }
        if(Fa) v[Fa].push_back(i);
    }
    int rt=mp[mk(1,n)];
    dfs(rt);
    double ans=Max;
    for(int i=B+1;i<=B+m;i++) ans+=dp[rt][i]*(i-B);
    printf("%.8lf\n",ans);
    return 0;
}