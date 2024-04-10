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
const int N=500005;
#define int long long
int a[N],n,b[N],ans=inf;

int highbit(int x){
    int ret=0;
    while((1ll<<ret)<=x) ret++;
    return ret;
}

void solve(int now,int cnt){
    if(cnt==1) {checkmin(ans,now); return;}
    vector<int> v[33];
    int t[33];
    for(int i=0;i<=31;i++) t[i]=0,v[i].clear();
    for(int i=1;i<=cnt;i++){
        int tmp=highbit(a[i]);
        t[tmp]++; v[tmp].push_back(a[i]);
    }
    //for(int i=0;i<=4;i++) cout<<t[i]<<" "; cout<<endl;
    int sum=0,tot=0;
    for(int i=0;i<=31;i++) if(t[i]) tot++;
    for(int i=0;i<=31;i++){
        if(!t[i]) continue;
        int m=0; tot--;
        for(auto &to : v[i]){
            if(i!=0) a[++m]=to-(1<<(i-1));             
            else a[++m]=to;    
        }
        //cout<<i<<" "<<m<<" "<<tot<<endl;
        solve(now+(cnt-m-tot-(sum!=0)),m);
        sum++;
    }
    for(int i=0;i<=31;i++) t[i]=0,v[i].clear();
}

signed main()
{
    n=read();
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    solve(0,n);
    cout<<ans<<endl;
    return 0;
}