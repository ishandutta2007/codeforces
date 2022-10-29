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
typedef vector<int> Poly;
Poly operator + (Poly A,Poly B){for(int i=0;i<sz(A);i++) A[i]+=B[i]; return A;}
const int N=1000005;
const int M=5005;
int bl[M],prime[M],tot=0,t[M],n;
void prepare(int n){
    for(int i=2;i<=n;i++){
        if(!bl[i]) prime[++tot]=i;
        for(int j=1;j<=tot;j++){
            if(i*prime[j]>n) break;
            bl[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
int m=5000,dis[M][M],mxf[N];
Poly f[M],sum[M];
int top=0,fa[N],fe[N],id[M][M];

int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        int x=read(); if(!x) x=1;
        t[x]++;
    }
    prepare(5000);
    for(int i=0;i<=m;i++) f[i].resize(tot+1),sum[i].resize(tot+1);
    for(int i=1;i<=m;i++){
        int x=i; f[i]=f[i-1];
        for(int j=1;j<=tot;j++) if(x%prime[j]==0){
            while(x%prime[j]==0) x/=prime[j],f[i][j]++;
            mxf[i]=j;
        }
        sum[i][tot]=f[i][tot]; 
        for(int j=tot-1;j>=1;j--) sum[i][j]=sum[i][j+1]+f[i][j];
    }
    for(int i=m;i>1;i--){
        int mx=0;
        for(int j=i-1;j>=1;j--){
            checkmax(mx,mxf[j+1]);
            dis[i][j]=sum[i][1]-sum[j][mx];
            dis[j][i]=sum[j][1]-sum[j][mx];
        }
    }
    ll ans=INF;
    for(int i=1;i<=m;i++){
        ll sum=0;
        vector<pii> v;
        for(int j=1;j<=m;j++){
            v.push_back(mk(dis[i][j],t[j]));
            sum+=1ll*t[j]*(dis[i][j]+dis[j][i]);
        }
        sort(v.begin(),v.end());
        int sz=0; checkmin(ans,sum);
        for(int j=1;j<sz(v);j++){
            sz+=v[j-1].second;
            int delta=v[j].first-v[j-1].first;
            sum=sum+1ll*delta*sz-1ll*delta*(n-sz);
            checkmin(ans,sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}