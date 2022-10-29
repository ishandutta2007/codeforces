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
const int N=200005;
int n,m,val[N];
ll sum=0,ans=0;
struct node{
    int x,y,mi;
    bool operator < (const node &rhs) const{
        return mi<rhs.mi;
    }
}a[N];

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i].x=read();
    for(int i=1;i<=n;i++) a[i].y=read();
    for(int i=1;i<=n;i++) sum+=_abs(a[i].x-a[i].y),a[i].mi=min(a[i].x,a[i].y);
    multiset<int> st1,st2;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i].x<=a[i].y){
            st1.insert(a[i].y);
            if(!st2.empty()) checkmax(ans,min(a[i].y,*(--st2.end()))-a[i].x);
        }
        else{
            st2.insert(a[i].x);
            if(!st1.empty()) checkmax(ans,min(a[i].x,*(--st1.end()))-a[i].y);
        }
    }
    out(sum); outln(ans);
    cout<<sum-ans*2<<endl;
    return 0;
}