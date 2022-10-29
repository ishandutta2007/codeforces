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
const int N=100005;
int n,b[N],a[N],q; ll st[N][18],sum[N];
int lg[N],nxt[N];
ll query(int l,int r){
    int sz=r-l+1;
    return max(st[l][lg[sz]],st[r-(1<<lg[sz])+1][lg[sz]]);
}

int main()
{
    n=read(); q=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read(),a[i]=b[i]-a[i];
    stack<int> stk;
    for(int i=0;i<=n;i++) nxt[i]=n+1;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    stk.push(0);
    for(int i=0;i<=n;i++){
        while(!stk.empty()&&sum[stk.top()]>sum[i]) nxt[stk.top()]=i,stk.pop();
        stk.push(i);
    }
    for(int i=1;i<=n;i++) st[i][0]=sum[i];
    for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
    for(int j=1;j<18;j++){
        for(int i=1;i<=n;i++){
            if(i+(1<<j)-1>n) break;
            int to=i+(1<<(j-1));
            st[i][j]=max(st[i][j-1],st[to][j-1]);
        }
    }
    while(q--){
        int l=read(),r=read();
        if((sum[r]-sum[l-1])||nxt[l-1]<=r){puts("-1"); continue;}
        printf("%lld\n",query(l,r)-sum[l-1]);
    }
    return 0;
}