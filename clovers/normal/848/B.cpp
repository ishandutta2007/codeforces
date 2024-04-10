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
const int B=100000;
struct node{
    int g,p,t,id;
    bool operator < (const node &rhs) const{
        return p<rhs.p;
    }
}a[N];
int n,w,h;
vector<int> v[N],v2[N];
deque<int> q[N];
pii ans[N];

int main()
{
    n=read(); w=read(); h=read();
    for(int i=1;i<=n;i++) a[i].g=read(),a[i].p=read(),a[i].t=read(),a[i].id=i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i].g==2) q[a[i].t-a[i].p+B].push_back(a[i].id),
                v2[a[i].t-a[i].p+B].push_back(a[i].p);
        else v[a[i].t-a[i].p+B].push_back(a[i].id);
    }
    for(int i=0;i<=B+B;i++) if(!q[i].empty()){
        for(auto &u : v[i]) q[i].pop_back(),q[i].push_front(u);
        int x=0;
        while(!q[i].empty()) ans[q[i].front()]=mk(w,v2[i][x]),x++,q[i].pop_front();
    }
    for(int i=0;i<=B+B;i++) v[i].clear(),v2[i].clear();

    for(int i=1;i<=n;i++){
        if(a[i].g==1) q[a[i].t-a[i].p+B].push_back(a[i].id),
                v2[a[i].t-a[i].p+B].push_back(a[i].p);
        else v[a[i].t-a[i].p+B].push_back(a[i].id);
    }
    for(int i=0;i<=B+B;i++) if(!q[i].empty()){
        for(auto &u : v[i]) q[i].pop_back(),q[i].push_front(u);
        int x=0;
        while(!q[i].empty()) ans[q[i].front()]=mk(v2[i][x],h),x++,q[i].pop_front();
    } 
    for(int i=1;i<=n;i++) printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}