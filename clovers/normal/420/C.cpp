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
const int N=300005;
int n,p; ll ans=0;
pii a[N];
namespace BIT{
    int a[N];
    int lowbit(int x){return x&(-x);}
    void update(int x,int val){
        for(int i=x;i<=n;i+=lowbit(i)) a[i]+=val; 
    }
    int query(int x){
        int ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=a[i];
        return ret;
    }
}

int t[N];
int main()
{
    n=read(); p=read();
    for(int i=1;i<=n;i++){
        a[i].first=read(),a[i].second=read();
        if(a[i].first>a[i].second) swap(a[i].first,a[i].second);
        t[a[i].first]++; t[a[i].second]++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) if(t[i]) BIT::update(t[i],1);
    for(int i=1,j=1;i<=n;i++){
        int pre=j;
        if(t[i]) BIT::update(t[i],-1);
        while(a[j].first==i&&j<=n){
            int y=a[j].second;
            BIT::update(t[y],-1); t[y]--; 
            if(t[y]) BIT::update(t[y],1);
            j++;
        }
        if(t[i]>=p) ans+=n-i;
        else ans+=BIT::query(n)-BIT::query(p-t[i]-1);
        j=pre;
        while(a[j].first==i&&j<=n){
            int y=a[j].second;
            if(t[y]) BIT::update(t[y],-1);
            t[y]++; BIT::update(t[y],1);
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}