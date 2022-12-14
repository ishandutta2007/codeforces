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
int n,a[N],val[N],m,nn;
vector<int> v[N];
struct node{
    int k,pos,id;
    bool operator < (const node &rhs) const{
        return k<rhs.k;
    }
}Q[N];

namespace BIT{
    int a[N];
    int lowbit(int x){return x&(-x);}
    void update(int x){
        for(int i=x;i<=n;i+=lowbit(i)) a[i]++;
    }
    int query(int x){
        int ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=a[i];
        return ret; 
    }
}
vector<int> G[N];

int ans[N];
void init(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),val[i]=a[i];
    sort(val+1,val+n+1);
    nn=unique(val+1,val+n+1)-val-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(val+1,val+nn+1,a[i])-val;
    for(int i=n;i>=1;i--) v[a[i]].push_back(i);
    m=read();
    for(int i=1;i<=m;i++){
        Q[i].k=read(),Q[i].pos=read(),Q[i].id=i;
        G[Q[i].k].push_back(i);
    }
}

int find(int x){
    int l=0,r=n,mid,best;
    while(l<=r){
        mid=(l+r)>>1;
        if(BIT::query(mid)>=x) best=mid,r=mid-1;
        else l=mid+1;
    }
    return best;
}

void solve(){
    int now=n;
    for(int i=1;i<=n;i++){
        while(v[now].empty()&&now>=1) now--;
        int pos=v[now].back(); v[now].pop_back();
        BIT::update(pos);
        for(auto &to : G[i]){
            node u=Q[to];
            ans[u.id]=find(u.pos);
        }
    }
    for(int i=1;i<=m;i++) printf("%d\n",val[a[ans[i]]]);
}

int main()
{
    init(); solve();
    return 0;
}