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
const int N=200005;
int n,m; ll dp[N][2],a[N];
struct Segment{ll l,r;}s[N];
vector<int> vl[N],vr[N];
bool cmp1(int i,int j){return s[i].l<s[j].l;}
bool cmp2(int i,int j){return s[i].r>s[j].r;}
int vis[N],id[N];

ll calc(int pos,ll typ1,ll typ2){
    int sz=sz(vr[pos]);
    if(!sz) return 0;
    ll ret=typ1*(s[vr[pos].back()].l-a[pos]),retl,retr;
    for(int i=0;i<sz;i++) id[vl[pos+1][i]]=i;    
    int now=0;
    for(int i=sz-1;i>=0;i--){
        checkmax(now,id[vr[pos][i]]);
        retl=typ1*(i==0 ? 0 : s[vr[pos][i-1]].l-a[pos]);
        retr=typ2*(a[pos+1]-s[vl[pos+1][now]].r);
        checkmin(ret,retl+retr);
    }
    return ret;
}

void solve(){
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    a[0]=-INF; a[n+1]=INF;
    for(int i=0;i<=n+1;i++) vl[i].clear(),vr[i].clear(),dp[i][0]=dp[i][1]=INF;
    for(int i=1;i<=m;i++){
        vis[i]=0;
        int l=read(),r=read();
        s[i]={l,r};
        int posl=lower_bound(a,a+n+2,l)-a-1;
        int posr=upper_bound(a,a+n+2,r)-a;
        if(posl+1==posr) vr[posl].push_back(i),vl[posr].push_back(i);
    }
    for(int i=0;i<=n+1;i++){
        sort(vr[i].begin(),vr[i].end(),cmp1);
        sort(vl[i].begin(),vl[i].end(),cmp2);
    }
    ll tmp=0;
    if(sz(vl[1])) tmp=a[1]-s[vl[1].back()].r;
    dp[1][0]=tmp; dp[1][1]=tmp*2;
    for(int i=1;i<=n;i++){
        dp[i+1][0]=dp[i][0]+calc(i,2,1);
        dp[i+1][1]=dp[i][0]+calc(i,2,2);
        checkmin(dp[i+1][0],dp[i][1]+calc(i,1,1));
        checkmin(dp[i+1][1],dp[i][1]+calc(i,1,2));
    }
    printf("%lld\n",dp[n+1][0]);
}

int main()
{
    int T=read();
    while(T--){solve();}
    return 0;
}