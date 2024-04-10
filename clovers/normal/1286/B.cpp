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
const int N=2005;
int n; vector<int> v[N];
int sz[N],c[N],Rt;
typedef vector<int> V;
void merge(V &A,V &B){
    for(int i=0;i<sz(B);i++) A.push_back(B[i]);
    B.clear();
}

void insert(V &A,int id,int k){
    V ret; ret.clear();
    if(!k) ret.push_back(id);
    for(int i=0;i<sz(A);i++){
        ret.push_back(A[i]);
        if(i+1==k) ret.push_back(id);
    }
    A=ret;
}

V dfs(int u){
    sz[u]=1; V ret;
    for(auto &to : v[u]){
        V tmp=dfs(to);
        merge(ret,tmp);
        sz[u]+=sz[to];
    }
    if(c[u]>=sz[u]) {puts("NO"); exit(0);}
    insert(ret,u,c[u]);
    return ret;
}

int ans[N];
int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        int fa=read(); c[i]=read();
        if(!fa) Rt=i;
        else v[fa].push_back(i);
    }
    V ret=dfs(Rt);
    for(int i=0;i<sz(ret);i++) ans[ret[i]]=i+1;
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}