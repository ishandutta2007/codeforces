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
const int N=55;
const int M=1100000;
int n,m; char s[N][N];
ll f[M],num[M];
void FWT(){
    for(int h=1;h<(1<<m);h<<=1){
        for(int i=0;i<(1<<m);i+=(h<<1)){
            for(int j=i;j<i+h;j++) f[j]|=f[j+h];
        }
    }
}

double dp[M];
signed main()
{
    n=read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    m=strlen(s[1]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) if(i!=j){
            int mask=0;
            for(int k=1;k<=m;k++) if(s[i][k]==s[j][k]) mask|=(1<<(k-1));
            f[mask]|=(1ll<<i);
        }
    }
    FWT();
    for(int i=0;i<(1<<m);i++) num[i]=__builtin_popcountll(f[i]);
    dp[0]=1; double ans=0;
    for(int S=0;S<(1<<m);S++){
        int cnt=__builtin_popcount(S);
        for(int i=0;i<m;i++) if(!(S>>i&1)){
            dp[S|(1<<i)]+=1.0*dp[S]/(m-cnt);
        }
        ans+=dp[S]*num[S];
    }
    printf("%.12lf\n",ans/n);
    return 0;
}