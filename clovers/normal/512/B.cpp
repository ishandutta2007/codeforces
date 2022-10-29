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
int n,top=0,dp[N][N*100],num[N*N];
struct node{
    int l,c;
}a[N];
map<int,int> mp;
int process(int x){
    for(int i=1;i*i<=x;i++){
        if(x%i==0){
            if(!mp.count(i)) mp[i]=++top,num[top]=i;
            if(!mp.count(x/i)) mp[x/i]=++top,num[top]=x/i;
        }
    }
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i].l=read(),process(a[i].l);
    for(int i=1;i<=n;i++) a[i].c=read();
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++) dp[i][mp[a[i].l]]=a[i].c;
    for(int i=1;i<n;i++){
        for(int j=1;j<=top;j++) if(dp[i][j]<inf){
            checkmin(dp[i+1][j],dp[i][j]);
            int to=__gcd(num[j],a[i+1].l);
            checkmin(dp[i+1][mp[to]],dp[i][j]+a[i+1].c);
        }
    }
    if(dp[n][mp[1]]>inf) cout<<-1<<endl;
    else cout<<dp[n][mp[1]]<<endl;
    return 0;
}