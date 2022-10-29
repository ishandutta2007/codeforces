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
int n,k,l,r;

signed main()
{
    scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
    r-=l; if(r<0) r+=n; r++;
    if(n<=3000000){
        for(int i=n;i>=0;i--){
            int sum=n+i;
            int rnd=(k-1)/sum,rest=k-rnd*sum;
            int L,R;
            if(rest<=n-i) R=rest;
            else{
                int tmp=rest-(n-i);
                R=n-i+(tmp+1)/2;
            }
            if(rest<=2*i) L=(rest+1)/2;
            else{
                int tmp=rest-2*i;
                L=i+tmp;
            }
            if(L<=r&&r<=R){
                printf("%lld\n",i);
                return 0;
            }
        }
        puts("-1");
        return 0;
    }
    int ans=-1;
    for(int c=0;c<=k/n;c++){
        int tmp1=k-n*c-r;
        int tmp2=n-r;
        int tmp=(tmp1+tmp2)/(c+1);
        int y=tmp1-c*tmp;
        if(tmp1>=0&&tmp<=n&&y<=r) checkmax(ans,tmp);
        tmp1++; tmp=(tmp1+tmp2)/(c+1);
        y=tmp1-c*tmp;
        if(tmp1>=0&&tmp<=n&&y<=r) checkmax(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}