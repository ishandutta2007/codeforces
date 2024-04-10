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
const int N=500005;
const int M=1005;
int n,fa[N]; vector<int> v[N];
double a[N],sum[N],ans=0;

void dfs(int u){
    for(auto &to : v[u]){
        if(to==fa[u]) continue;
        fa[to]=u;
        dfs(to); sum[u]+=1-a[to];
    }
    ans+=a[u]*sum[u];
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
    for(int i=1;i<n;i++){
        int x=read()+1,y=read()+1;
        v[x].push_back(y); v[y].push_back(x);
    }
    dfs(1); ans+=(1-a[1]);
    int Q=read();
    while(Q--){
        int x=read()+1; double P; scanf("%lf",&P);
        if(x!=1){
            ans-=(1-a[x])*a[fa[x]],sum[fa[x]]-=(1-a[x]);
            ans-=a[x]*sum[x];
            a[x]=P;
            ans+=(1-a[x])*a[fa[x]],sum[fa[x]]+=(1-a[x]);
            ans+=a[x]*sum[x];
        }
        else{
            ans-=(1-a[1]);
            ans-=a[x]*sum[x];
            a[x]=P;
            ans+=(1-a[1]);
            ans+=a[x]*sum[x];
        }
        printf("%.5lf\n",ans);
    }
    return 0;
}