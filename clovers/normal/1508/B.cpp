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
#define int long long
int n,k,top;
int a[N],b[N],tot=0;
void solve(int st){
    if(st>n) return;
    int rest=n-st-1,cnt=0;
    while(rest>=0&&b[rest]) cnt++,rest--;
    for(int i=st+cnt;i>=st;i--) a[++top]=i;
    solve(st+cnt+1);
}

signed main()
{
    int T=read();
    while(T--){
        top=0;
        scanf("%lld%lld",&n,&k);
        k--;
        int x=k; tot=0;
        while(x){
            b[tot++]=(x&1);
            x>>=1;
        } tot--;
        if(tot>n-1||b[n-1]==1){
            puts("-1");
            for(int i=0;i<=tot;i++) b[i]=0;
            continue;
        }
        solve(1);
        for(int i=1;i<=n;i++) printf("%lld ",a[i]);
        for(int i=0;i<=tot;i++) b[i]=0;
        puts("");
    }
    return 0;
}