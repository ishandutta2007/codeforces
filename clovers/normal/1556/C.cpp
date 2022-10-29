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
#define int long long
const int N=1005;
int n,a[N];

signed main()
{
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    int ans=0;
    for(int i=1;i<=n;i+=2){
        int sum=0,rest=a[i],bl=0;
        for(int j=i+1;j<=n;j++){
            if(j%2==0){
                int to=sum-a[j];
                if(to<=0){
                    if(sum>0) ans+=min(-to,rest)+bl;
                    else if(rest+to>=0) ans+=a[j];
                    else ans+=(rest+sum);
                    if(rest+to<0) break;
                    rest+=to; sum=0; bl=1;
                }
                else sum=to;
            }
            else sum+=a[j];
            // out(j); out(sum); out(rest); outln(ans);
        }
        // out(i); outln(ans);
    }
    cout<<ans<<endl;
    return 0;
}