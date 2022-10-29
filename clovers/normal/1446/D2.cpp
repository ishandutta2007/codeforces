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
const int N=200005;
const int M=1005;
int n,a[N],t[N],id=0;
bool check(){for(int i=1;i<n;i++) if(a[i]!=a[i+1]) return 0; return 1;}

void init(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),t[a[i]]++;
    if(check()){puts("0"); exit(0);}
    int tot=1;
    for(int i=1;i<=n;i++){
        if(t[i]>t[id]) id=i,tot=1;
        else if(t[i]==t[id]) tot++;
    }
    if(tot>=2){
        printf("%d\n",n);
        exit(0);
    }
}

const int B=200000;
int b[N],sum[N],pre[N<<1],ans=0;
void solve1(int X,int Y){
    for(int i=1;i<=n;i++) 
        if(a[i]==X) b[i]=-1;
        else if(a[i]==Y) b[i]=1;
        else b[i]=0;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+b[i];
    memset(pre,-1,sizeof(pre));
    pre[B]=0;
    for(int i=1;i<=n;i++){
        if(pre[sum[i]+B]!=-1) checkmax(ans,i-pre[sum[i]+B]);
        else pre[sum[i]+B]=i;
    }
}

void solve2(int T){
    memset(t,0,sizeof(t));
    int now=0;
    for(int i=1,j=0;i<=n;i++){//j+1~i
        t[a[i]]++;
        if(t[a[i]]==T) now++;
        if(t[a[i]]==T+1){
            while(t[a[i]]==T+1){
                t[a[++j]]--;
                if(t[a[j]]==T-1) now--;
            }
        }
        if(now>=2) checkmax(ans,i-j);
    }
}

int main()
{
    init();
    for(int i=1;i<=n;i++){
        if(1ll*t[i]*t[i]>=n&&i!=id) solve1(id,i);
    }
    for(int i=1;i*i<=n;i++) solve2(i);
    cout<<ans<<endl;
    return 0;
}