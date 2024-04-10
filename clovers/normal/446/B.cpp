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
const int N=1005;
priority_queue<ll> q1,q2;
int n,m,k,a[N][N],p;
ll A[N*N],B[N*N];
ll ans=-INF,tag1=0,tag2=0;

int main()
{
    n=read(); m=read(); k=read(); p=read();
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) a[i][j]=read();
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=m;j++) sum+=a[i][j];
        q1.push(sum);
    }
    for(int j=1;j<=m;j++){
        int sum=0;
        for(int i=1;i<=n;i++) sum+=a[i][j];
        q2.push(sum);
    }
    for(int i=1;i<=k;i++){
        A[i]=A[i-1]+q1.top();
        int u=q1.top()-p*m; q1.pop(); q1.push(u);
    }
    for(int i=1;i<=k;i++){
        B[i]=B[i-1]+q2.top();
        int u=q2.top()-p*n; q2.pop(); q2.push(u);
    }
    for(int i=0;i<=k;i++){
        checkmax(ans,A[i]+B[k-i]-1ll*i*(k-i)*p);
    }
    cout<<ans<<endl;
    return 0;
}