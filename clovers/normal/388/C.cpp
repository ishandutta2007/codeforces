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
const int N=105;
int n,s[N],a[N][N];
int b[N],ans1=0,ans2=0;

int main()
{
    n=read();
    int top=0;
    for(int i=1;i<=n;i++){
        s[i]=read();
        for(int j=1;j<=s[i];j++) a[i][j]=read();
        for(int j=1;j<=s[i]/2;j++) ans1+=a[i][j];
        for(int j=s[i];j>=s[i]-s[i]/2+1;j--) ans2+=a[i][j];
        if(s[i]&1) b[++top]=a[i][s[i]/2+1];
    }
    sort(b+1,b+top+1);
    for(int i=top;i>=1;i-=2) ans1+=b[i];
    for(int i=top-1;i>=1;i-=2) ans2+=b[i];
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}