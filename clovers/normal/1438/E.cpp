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
const int N=200005;
int n,a[N],nxt[N][30];
ll sum[N];
set<pii> st;

int main()
{
    n=read(); for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
    for(int i=0;i<30;i++) nxt[n][i]=n+1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<30;j++){
            nxt[i][j]=nxt[i+1][j];
        }
        int b;
        for(int j=0;j<30;j++) if(a[i+1]>>j&1) b=j;
        nxt[i][b]=i+1;
    }
    int ans=0;
    for(int l=1;l<=n-2;l++){
        int b=0;
        for(int i=0;i<30;i++) if(a[l]>>i&1) b=i;
        for(int i=0;i<30;i++){
            int tmp=(a[l]^(1<<i)),mi=min(i,b);
            tmp>>=mi; tmp<<=mi;
            if(i==b) tmp=0; else if(i>b) tmp=(1<<i);
            int r=lower_bound(sum+1,sum+n+1,sum[l]+tmp)-sum;
            r=nxt[r][i];
            if(r!=n+1&&r>l+1&&sum[r-1]-sum[l]==(a[r]^a[l])) st.insert(mk(l,r));
        }
    }
    cout<<sz(st)<<endl;
    return 0;
}