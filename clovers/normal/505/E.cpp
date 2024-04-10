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
const int N=100005;
int n,m,k,p;
int a[N],h[N],mx=0,mx2=0;
struct node{
    int val,a,id;
    bool operator < (const node &rhs) const{
        return (double)val*rhs.a>(double)rhs.val*a;
    }
};
priority_queue<node> q;
int num[N];
bool check(int mid){
    memset(num,0,sizeof(num));
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++) q.push({mid,a[i],i});
    for(int rnd=1;rnd<=m;rnd++){
        node u=q.top();
        if(u.val-u.a*rnd<0) return 0;
        for(int i=1;i<=k;i++){
            u=q.top(); q.pop();
            num[u.id]++; u.val+=p;
            q.push(u);
        }
    }
    int rest=0;
    for(int i=1;i<=n;i++){
        int now=mid+num[i]*p-a[i]*m;
        if(now>h[i]) rest+=min(num[i],(now-h[i])/p);
        else{
            int delta=(h[i]-now+p-1)/p;
            rest-=delta;
        }
    }
    return rest>=0;
}

signed main()
{
    n=read(); m=read(); k=read(); p=read();
    for(int i=1;i<=n;i++){
        h[i]=read(),a[i]=read();
        checkmax(mx,h[i]+a[i]*m);
        checkmax(mx2,a[i]);
    }
    int l=mx2,r=mx,mid,best;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)) r=mid-1,best=mid;
        else l=mid+1;
    }
    cout<<best<<endl;
    return 0;
}