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
const int N=500005;
const int M=1000005;
int n,a[N],t[M],tmp[N];

int main()
{
    int T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++) a[i]=read(),t[a[i]]++,tmp[i]=a[i];
        sort(a+1,a+n+1);
        int m=unique(a+1,a+n+1)-a-1;
        if(m<=2){
            puts("0 0 0");
            for(int i=1;i<=n;i++) t[tmp[i]]--;
            continue;
        }
        int g=t[a[m]],b=0,s=0;
        int x=m-1;
        while(x>0&&s+t[a[x]]<=g) s+=t[a[x]],x--;
        if(x>0) s+=t[a[x]]; x--;
        while(x>0&&b+t[a[x]]<=g) b+=t[a[x]],x--;
        if(x>0) b+=t[a[x]]; x--;
        while(x>0&&s+b+g+t[a[x]]<=n/2) b+=t[a[x]],x--;
        if(g+s+b>n/2||g>=s||g>=b) puts("0 0 0");
        else printf("%d %d %d\n",g,s,b);
        for(int i=1;i<=n;i++) t[tmp[i]]--;
    }
    return 0;
}