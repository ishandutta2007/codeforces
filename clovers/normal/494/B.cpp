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
const int MOD=1e9+7;
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
int n,m,g[N],dp[N]; char s[N],t[N];
int nxt[N],f[N],p[N],bl[N];
void init(){
    nxt[1]=0;
    for(int i=1;i<m;i++){
        int j=nxt[i];
        while(j&&t[j+1]!=t[i+1]) j=nxt[j];
        if(t[j+1]==t[i+1]) j++;
        nxt[i+1]=j;
    }
    f[0]=0;
    for(int i=0;i<n;i++){
        int j=f[i];
        if(j==m) j=nxt[j];
        while(j&&t[j+1]!=s[i+1]) j=nxt[j];
        if(t[j+1]==s[i+1]) j++;
        f[i+1]=j;
    }
    for(int i=1;i<=n;i++) if(f[i]==m) bl[i-m+1]=1;
    p[n+1]=n+1;
    for(int i=n;i>=1;i--) if(bl[i]) p[i]=i; else p[i]=p[i+1];
}

int main()
{
    scanf("%s",s+1); scanf("%s",t+1);
    n=strlen(s+1); m=strlen(t+1);
    init();
    int flag=0;
    for(int i=1;i<=n;i++) flag|=(f[i]==m);
    if(!flag){puts("0"); return 0;}
    dp[0]=1; g[1]=0; int sum=0;
    for(int i=0;i<n;i++){
        Add(dp[i],g[i]); Add(g[i+1],g[i]); Add(sum,dp[i]);
        int to=p[i+1]+m-1;
        Add(g[to],sum);
    }
    Add(dp[n],g[n]);
    int ans=0;
    for(int i=1;i<=n;i++) Add(ans,dp[i]); 
    cout<<ans<<endl;
    return 0;
}