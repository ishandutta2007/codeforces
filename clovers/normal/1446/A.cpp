/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
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
const int N=500005;
ll T,n,W,sum=0;
pii a[N];

void solve(){
    ll now=0; vector<int> v; v.clear();
    for(int i=1;i<=n;i++){
        if(now+a[i].first>=(W+1)/2){
            if(now+a[i].first>W){
                if(a[i].first>W){
                    puts("-1");
                    return;
                }
                puts("1");
                printf("%lld\n",a[i].second);
                return;
            }
            v.push_back(a[i].second);
            printf("%d\n",sz(v));
            for(auto &to : v){
                printf("%d ",to);
            } puts("");
            return;
        }
        else v.push_back(a[i].second),now+=a[i].first;
    }
    puts("-1");
}

int main()
{
    cin>>T;
    while(T--){
        n=read(); scanf("%lld",&W); sum=0;
        for(int i=1;i<=n;i++) 
            scanf("%lld",&a[i].first),sum+=a[i].first,a[i].second=i;
        sort(a+1,a+n+1);
        if(sum<(W+1)/2){
            puts("-1");
            continue;
        }
        solve();
    }
    return 0;
}