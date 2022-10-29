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
const int N=18;
const int M=(1<<N);
int n,cnt[M],full;
char s[N+5][N+5];
ll dp[M][N],g[N][M];
void FWTor(ll *f,int len,int typ){
    for(int h=1;h<len;h<<=1){
        for(int i=0;i<len;i+=(h<<1)){
            for(int j=i;j<i+h;j++) f[j+h]+=typ*f[j];
        }
    }
}
void FWTand(ll *f,int len,int typ){
    for(int h=1;h<len;h<<=1){
        for(int i=0;i<len;i+=(h<<1)){
            for(int j=i;j<i+h;j++) f[j]+=typ*f[j+h];
        }
    }
}
ll f[M];
map<vector<int>,ll> mp;
vector<int> v; int tot=0;
void dfs(int s,int now,const vector<ll> &f){
    vector<ll> ret;
    ret.resize(full);
    if(s==n){
        ll ret=0;
        for(int S=0;S<full;S++){
            int flag=((n-cnt[S])&1 ? -1 : 1);
            ret+=flag*f[S];
        }
        mp[v]=ret; return;
    }
    for(int i=now;i+s<=n;i++){
        v.push_back(i);
        for(int S=0;S<full;S++) ret[S]=f[S]*g[i][S];
        dfs(s+i,i,ret);
        v.pop_back();
    }
}

int main()
{
    n=read();
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    for(int i=0;i<n;i++) dp[1<<i][i]=1;
    full=(1<<n);
    for(int S=1;S<full-1;S++){
        for(int i=0;i<n;i++) if(S>>i&1){
            if(!dp[S][i]) continue;
            for(int j=0;j<n;j++) if(!(S>>j&1)&&s[i][j]=='1'){
                dp[S^(1<<j)][j]+=dp[S][i];
            }
        }
    }
    for(int i=0;i<full;i++) cnt[i]=__builtin_popcount(i);
    for(int i=1;i<full;i++){
        for(int j=0;j<n;j++) g[cnt[i]][i]+=dp[i][j];
    }
    for(int i=1;i<=n;i++) FWTor(g[i],full,1);
    vector<ll> tmp; for(int i=0;i<full;i++) tmp.push_back(1);
    dfs(0,1,tmp);
    for(int S=0;S<full/2;S++){
        int pre=-1; vector<int> p;
        for(int i=0;i<n-1;i++){
            if(!(S>>i&1)) p.push_back(i-pre),pre=i;
        }
        p.push_back(n-1-pre);
        sort(p.begin(),p.end());
        f[S]=mp[p];
    }
    FWTand(f,full/2,-1);
    for(int i=0;i<full/2;i++) printf("%lld ",f[i]);
    return 0;
}