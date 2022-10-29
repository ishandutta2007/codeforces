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
const int N=2005;
int vis[N],n;
ll a[N];
ll ask(){
    vector<int> v;
    for(int i=1;i<=n;i++) if(!vis[i]) v.push_back(i);
    if(!sz(v)) return 0;
    printf("? ");
    printf("%d ",sz(v));
    for(auto &to : v) printf("%d ",to);
    puts(""); fflush(stdout);
    ll x=read(); return x;
}
int id[N],top=0;

int main()
{
    n=read();
    for(int i=1;i<(1<<13);i++){
        if(__builtin_popcount(i)==6) id[++top]=i;
    }
    for(int b=0;b<13;b++){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++) if(id[i]>>b&1) vis[i]=1;
        a[b]=ask();
    }
    printf("! ");
    for(int i=1;i<=n;i++){
        ll ret=0;
        for(int b=0;b<13;b++) if(id[i]>>b&1) ret|=a[b];
        printf("%lld ",ret); 
    }
    fflush(stdout);
    return 0;
}