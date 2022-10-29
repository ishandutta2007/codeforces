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
const int N=205;
int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};//17
int n,a[N];
int dp[102][1<<17],t[N]; vector<int> v[1<<17];
int pre[102][1<<17];

int main()
{
    n=read(); for(int i=1;i<=n;i++) a[i]=read();
    int full=(1<<17)-1;
    for(int i=1;i<=59;i++){
        for(int j=0;j<17;j++) 
            if(i%p[j]==0) t[i]|=(1<<j);
    }
    for(int S=0;S<=full;S++){
        for(int i=1;i<=59;i++){
            if((S&t[i])==0) v[S].push_back(i);
        }
    }
    memset(dp,0x3f,sizeof(dp)); dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int S=0;S<=full;S++) if(dp[i][S]<inf){
            for(auto &u : v[S]){
                if(dp[i+1][S|t[u]]>dp[i][S]+_abs(u-a[i+1])){
                    dp[i+1][S|t[u]]=dp[i][S]+_abs(u-a[i+1]);
                    pre[i+1][S|t[u]]=u;
                }
            }
        }
    }
    int ans=inf,x=0,mask;
    for(int S=0;S<=full;S++){
        if(dp[n][S]<ans) x=pre[n][S],mask=S,ans=dp[n][S];
    }
    vector<int> ret;
    for(int i=n-1;i>=0;i--){
        ret.push_back(x);
        mask^=t[x]; x=pre[i][mask];
    }
    reverse(ret.begin(),ret.end());
    for(auto &u : ret) printf("%d ",u);
    return 0;
}