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
struct node{
    int x,y;
}a[N];
vector<int> v[N];
int val[N],n,m; ll ans=0;
struct Segment_Tree{
    int val[N<<2],sum[N<<2];
    void pushup(int x){sum[x]=sum[x<<1]+sum[x<<1|1];}
    void insert(int x,int l,int r,int pos,int Val){
        if(l==r){
            val[x]+=Val;
            sum[x]=(val[x] ? 1 : 0);
            return;
        }
        int mid=(l+r)>>1;
        if(mid>=pos) insert(x<<1,l,mid,pos,Val);
        else insert(x<<1|1,mid+1,r,pos,Val);
        pushup(x);
    }
    int query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return sum[x];
        int mid=(l+r)>>1,ret=0;
        if(mid>=L) ret+=query(x<<1,l,mid,L,R);
        if(mid<R) ret+=query(x<<1|1,mid+1,r,L,R);
        return ret;
    }
}T;

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
    for(int i=1;i<=n;i++) val[i]=a[i].y;
    sort(val+1,val+n+1); m=unique(val+1,val+n+1)-val-1;
    for(int i=1;i<=n;i++) a[i].y=lower_bound(val+1,val+m+1,a[i].y)-val;
    int tot=m;
    for(int i=1;i<=n;i++) val[i]=a[i].x;
    sort(val+1,val+n+1); m=unique(val+1,val+n+1)-val-1;
    for(int i=1;i<=n;i++) a[i].x=lower_bound(val+1,val+m+1,a[i].x)-val;
    for(int i=1;i<=n;i++) v[a[i].y].push_back(a[i].x);
    for(int i=tot;i>=1;i--){
        if(v[i].empty()) continue;
        int mi=inf,mx=0;
        vector<int> tt; tt.clear();
        for(auto &to : v[i]){
            T.insert(1,1,m,to,1);
            checkmin(mi,to); checkmax(mx,to);
            tt.push_back(to);
        }
        sort(tt.begin(),tt.end());
        for(int j=1;j<sz(tt);j++){
            if(tt[j-1]+1<=tt[j]-1){
                int tmp=T.query(1,1,m,tt[j-1]+1,tt[j]-1);
                ans-=1ll*tmp*(tmp+1)/2;
            }
        }
        int S=T.sum[1];
        if(mx<m){
            int tmp=T.query(1,1,m,mx+1,m);
            ans-=1ll*tmp*(tmp+1)/2;
        }
        if(mi>1){
            int tmp=T.query(1,1,m,1,mi-1);
            ans-=1ll*tmp*(tmp+1)/2;
        }
        ans+=1ll*S*(S+1)/2;
    }
    cout<<ans<<endl;
    return 0;
}