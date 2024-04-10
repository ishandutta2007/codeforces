
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
const int MOD=1e9+7;
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
int T,n,cnt[70],Base[70]; ll a[N];

int main()
{
    T=read();
    Base[0]=1; for(int i=1;i<=65;i++) Base[i]=mul(Base[i-1],2);
    while(T--){
        n=read();
        for(int i=0;i<60;i++) cnt[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            for(int j=0;j<60;j++){
                if(a[i]>>j&1) cnt[j]++;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int sum1=0,sum2=0;
            for(int j=0;j<60;j++){
                if(a[i]>>j&1){
                    Add(sum2,mul(n,Base[j]));
                    Add(sum1,mul(cnt[j],Base[j]));
                }
                else Add(sum2,mul(cnt[j],Base[j]));
            }
            Add(ans,mul(sum1,sum2));
        }
        printf("%d\n",ans);
    }
    return 0;
}