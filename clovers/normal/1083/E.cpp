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
inline ll read(){
    ll x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=1000005;
struct node{
    int x,y; ll val;
    bool operator < (const node &rhs) const{
        return x<rhs.x;
    }
}a[N]; int n;
ll dp[N],ans=0;
vector<int> stk;
double slope(int x,int y){return 1.0*(dp[y]-dp[x])/(a[y].x-a[x].x);}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].val=read();
    sort(a+1,a+n+1);
    stk.push_back(0); stk.push_back(1);
    dp[1]=(ll)a[1].x*a[1].y-a[1].val; ans=dp[1];
    int be=0;
    for(int i=2;i<=n;i++){
        while(sz(stk)-be>=2&&slope(stk[be],stk[be+1])>=a[i].y) be++;
        dp[i]=dp[stk[be]]+(ll)a[i].y*(a[i].x-a[stk[be]].x)-a[i].val;
        checkmax(ans,dp[i]);
        while(sz(stk)-be>=2&&
            slope(stk[sz(stk)-2],stk.back())<=slope(stk.back(),i)) stk.pop_back();
        stk.push_back(i); 
    }
    cout<<ans<<endl;
    return 0;
}