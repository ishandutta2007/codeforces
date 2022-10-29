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
const int N=100005;
int G[N<<2],IG[N<<2];
typedef vector<int> Poly;
void print(Poly A){
    for(int i=0;i<(int)A.size();i++) printf("%d ",A[i]);
    puts("");
}
namespace FFT{
    int rev[N<<2];
    int init(int n){
        int len=1; while(len<n) len<<=1;
        rev[0]=0; 
        for(int i=1;i<len;i++) rev[i]=(rev[i>>1]>>1)+(i&1 ? len>>1 : 0);
        return len;
    }
    void ntt(Poly &a,int len,int flag){
        for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
        for(int h=1;h<len;h<<=1){
            int wn=(flag==-1 ? IG[h<<1] : G[h<<1]);
            for(int i=0;i<len;i+=(h<<1)){
                int W=1,tmp1,tmp2;
                for(int j=i;j<i+h;j++,Mul(W,wn)){
                    tmp1=a[j],tmp2=mul(a[j+h],W);
                    a[j]=add(tmp1,tmp2);
                    a[j+h]=sub(tmp1,tmp2);
                }
            }
        }
        if(flag==-1){
            int invlen=qpow(len,MOD-2);
            for(int i=0;i<len;i++) Mul(a[i],invlen);
        }
    }
    void multi(Poly &a,Poly b,int len){
        ntt(a,len,1); ntt(b,len,1);
        for(int i=0;i<len;i++) Mul(a[i],b[i]);
        ntt(a,len,-1);
    }
}
Poly operator * (Poly A,Poly B){
    int M=(int)A.size()+(int)B.size()-1;
    int len=FFT::init(M);
    A.resize(len); B.resize(len);
    FFT::multi(A,B,len);
    A.resize(M);
    return A;
}
Poly operator + (Poly A,Poly B){
    int len=max((int)A.size(),(int)B.size());
    A.resize(len); B.resize(len);
    for(register int i=0;i<len;++i) Add(A[i],B[i]);
    return A;
}
Poly mulX(Poly A){
    int M=(int)A.size();
    A.resize(M+1);
    for(int i=M;i>=1;i--) A[i]=A[i-1];
    A[0]=0;
    return A;
}
Poly sub0(Poly A){Add(A[0],MOD-1); return A;}
Poly add0(Poly A){Add(A[0],1); return A;}

Poly a[N];
void CDQ(Poly &F,Poly &G,int l,int r){
    if(l==r) {F=add0(a[l]),G=a[l]; return;}
    int mid=(l+r)>>1;
    Poly Fl,Fr,Gl,Gr;
    CDQ(Fl,Gl,l,mid); CDQ(Fr,Gr,mid+1,r);
    G=Gl*Gr; F=sub0(Fl)*Gr+Fr;
}

vector<int> v[N]; int n;
int son[N][2],sz[N];
void dfs1(int u,int f){
    sz[u]=1; int cnt=0;
    for(auto &to : v[u]){
        if(to==f) continue;
        dfs1(to,u); sz[u]+=sz[to];
        son[u][cnt++]=to;
    }
    if(cnt==2&&sz[son[u][0]]<sz[son[u][1]]) swap(son[u][0],son[u][1]);
}

int top[N];
Poly dp[N];
void dfs2(int u){
    if(son[u][0]) top[son[u][0]]=top[u],dfs2(son[u][0]);
    if(son[u][1]) top[son[u][1]]=son[u][1],dfs2(son[u][1]);
    if(top[u]==u){
        int m=0,now=u;
        Poly One; One.clear(); One.push_back(1);
        while(now){
            if(son[now][1]) a[++m]=mulX(dp[son[now][1]]);
            else a[++m]=mulX(One);
            now=son[now][0];
        }
        reverse(a+1,a+m+1);
        Poly G; CDQ(dp[u],G,1,m);
    }
}

ll X; int C[N];
void init(){
    for(int i=1;i<N*4;i<<=1){
        G[i]=qpow(3,(MOD-1)/i);
        IG[i]=qpow(G[i],MOD-2);
    }
    n=read(); scanf("%lld",&X); X%=MOD;
    C[0]=1; for(int i=1;i<=n;i++) dp[i].clear();
    for(int i=1;i<=n;i++){
        int A=add(X,i),B=i;
        C[i]=mul(C[i-1],mul(A,qpow(B,MOD-2)));
    }
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
}

void solve(){
    int ans=0;
    for(int i=1;i<=n;i++){
        Add(ans,mul(dp[1][i],C[i-1]));
    }
    cout<<ans<<endl;
}

int main()
{
    init(); 
    dfs1(1,-1);
    top[1]=1; dfs2(1);
    solve();
    return 0;
}