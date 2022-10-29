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
int n,k,a[N];
int b[N],top=0;
vector<vector<int> > ans;
int dp[N],vis[N],pre[N];
bool check(int n,int k){return n<(k+1)*(k+2)/2;}
void solve(int n,int k){
    if(!n) return;
    vector<int> v; v.clear();
    int ret=0; dp[0]=0;
    for(int i=1;i<=n;i++){
        int pos=lower_bound(dp,dp+ret+1,a[i])-dp-1;
        if(pos==ret) dp[++ret]=a[i],pre[a[i]]=dp[pos];
        else if(dp[pos+1]>a[i]){
            dp[pos+1]=a[i];
            pre[a[i]]=dp[pos];
        }
    }
    if(check(n-ret,k-1)){
        int x=dp[ret];
        while(x) v.push_back(x),vis[x]=1,x=pre[x];
        reverse(v.begin(),v.end()); ans.push_back(v);
        top=0; for(int i=1;i<=n;i++) if(!vis[a[i]]) b[++top]=a[i];
        for(int i=1;i<=top;i++) a[i]=b[i]; n=top;
        solve(n,k-1); 
    }
    else{
        vector<vector<int> > vv;
        for(int i=1;i<=n;i++){
            int bl=1;
            for(auto &v : vv) if(v.back()>a[i]){
                v.push_back(a[i]);
                bl=0;
                break;
            }
            if(bl){
                v.clear(); v.push_back(a[i]);
                vv.push_back(v);
            }
        }
        for(auto &v : vv) ans.push_back(v); return;
    }
}

int main()
{
    int T=read();
    while(T--){
        ans.clear();
        n=read(); for(int i=1;i<=n;i++) a[i]=read(),vis[i]=0;
        k=1; while((k+1)*(k+2)/2<=n) k++;
        solve(n,k);
        printf("%d\n",sz(ans));
        for(auto &v : ans){
            printf("%d ",sz(v));
            for(auto &to : v) printf("%d ",to); puts("");
        }
    }
    return 0;
}