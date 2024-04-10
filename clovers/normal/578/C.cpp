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
int n; double a[N],sum[N],b[N];

double calc(double mid){
    for(int i=1;i<=n;i++) a[i]=b[i]-mid;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    double mi=0,mx=0,ret=0;
    for(int i=1;i<=n;i++){
        ret=max(ret,max(mx-sum[i],sum[i]-mi));
        mx=max(sum[i],mx); mi=min(sum[i],mi);
    }
    return ret;
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]),b[i]=a[i];
    double l=-10000.0,r=10000.0,mid1,mid2,best;
    for(int ttt=1;ttt<=100;ttt++){
        mid1=(l+l+r)/3.0; mid2=(l+r+r)/3.0;
        double ret1=calc(mid1),ret2=calc(mid2);
        if(ret1<ret2) r=mid2,best=ret1;
        else l=mid1,best=ret2;
    }
    printf("%.8lf\n",best);
    return 0;
}