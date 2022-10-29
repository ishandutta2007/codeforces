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
int T,n,a[N],sum[N];
void solve(){
    vector<int> v;
    n=read(); for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]^a[i];
    if(sum[n]){puts("NO"); return;}
    if(n&1){
        puts("YES");
        for(int i=1;i<n;i+=2) v.push_back(i);
        printf("%d\n",sz(v)*2);
        for(int i=0;i<sz(v);i++) printf("%d ",v[i]);
        for(int i=sz(v)-1;i>=0;i--) printf("%d ",v[i]); puts("");
        return;
    }
    else{
        for(int i=1;i<=n;i+=2) if(!sum[i]){
            for(int j=1;j<i;j+=2) v.push_back(j);
            for(int j=i-2;j>=1;j-=2) v.push_back(j);
            for(int j=i+1;j<n;j+=2) v.push_back(j);
            for(int j=n-2;j>=i+1;j-=2) v.push_back(j);
            break;
        }
        if(sz(v)){
            puts("YES"); printf("%d\n",sz(v));
            for(auto &u : v) printf("%d ",u); puts("");
            return;
        } 
    }
    puts("NO");
}

int main()
{
    T=read();
    while(T--) solve();
    return 0;
}