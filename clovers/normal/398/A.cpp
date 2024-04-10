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
#define int long long
int n,a,b; char s[N];

signed main()
{
    a=read(); b=read(); n=a+b;
    if(!a){
        printf("%lld\n",-b*b);
        for(int i=1;i<=n;i++) printf("x");
        return 0;
    }
    if(!b||b==1){
        printf("%lld\n",a*a-b);
        for(int i=1;i<=a;i++) printf("o");
        if(b) printf("x");
        return 0;
    }
    int ans=-INF,best=-1;
    for(int i=1;i<=min(a,b-1);i++){
        int c=a-i+1,tmp=c*c+a-c;
        int d=b/(i+1),rest=b%(i+1);
        tmp-=(d*d*(i+1-rest)+(d+1)*(d+1)*rest);
        if(ans<tmp) ans=tmp,best=i;
    }
    cout<<ans<<endl;
    int d=b/(best+1),rest=b%(best+1);
    for(int i=1;i<=rest;i++){
        for(int j=1;j<=d+1;j++) printf("x");
        if(i==1) for(int j=1;j<=a-best+1;j++) printf("o");
        else printf("o");
    }
    for(int i=rest+1;i<=best+1;i++){
        for(int j=1;j<=d;j++) printf("x");
        if(i==best+1) continue;
        if(i==1) for(int j=1;j<=a-best+1;j++) printf("o");
        else printf("o");
    }
    return 0;
}