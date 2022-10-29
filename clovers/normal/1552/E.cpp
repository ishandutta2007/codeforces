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
const int N=105;
int vis[N*N],bl[N],a[N*N],n,k,top=0;
pii p[N];

int main()
{
    n=read(); k=read();
    for(int i=1;i<=n*k;i++) a[i]=read();
    for(int i=1;i<=n;i++) p[i]=mk(0,0);
    int lim=(n+k-2)/(k-1);
    for(int i=1;i<=n*k;i++) if(!bl[a[i]]){
        for(int j=i-1;j>=1;j--){
            if(vis[j]==lim) break;
            if(a[j]==a[i]){
                p[a[i]]=mk(j,i);
                for(int kk=j;kk<=i;kk++) vis[kk]++;
                bl[a[i]]=1;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++) assert(p[i].first);
    for(int i=1;i<=n;i++) printf("%d %d\n",p[i].first,p[i].second);
    return 0;
}