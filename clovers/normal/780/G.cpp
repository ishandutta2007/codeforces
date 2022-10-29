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
const int N=100005;
int h,w,n,dp[N];
struct Line{
    int h,l,r,s;
    bool operator < (const Line &rhs) const{
        return h<rhs.h;
    }
}a[N];

struct Segment_Tree{
    vector<int> v[N<<2];
    int find(int x,int h){
        if(v[x].empty()) return 0;
        while(!v[x].empty()){
            int u=v[x].back();
            if(a[u].h+a[u].s<h) v[x].pop_back();
            else return u;
        }
        return 0;
    }
    int query(int x,int l,int r,int pos,int h){
        if(l==r) return find(x,h);
        int u1=find(x,h),u2=0;
        int mid=(l+r)>>1;
        if(mid>=pos) u2=query(x<<1,l,mid,pos,h);
        else u2=query(x<<1|1,mid+1,r,pos,h);
        return a[u1].h>a[u2].h ? u1 : u2;
    }
    void update(int x,int l,int r,int L,int R,int id){
        if(L<=l&&r<=R){v[x].push_back(id); return;}
        int mid=(l+r)>>1; 
        if(mid>=L) update(x<<1,l,mid,L,R,id);
        if(mid<R) update(x<<1|1,mid+1,r,L,R,id);
    }
}tree;

int main()
{
    h=read(); w=read(); n=read();
    a[0].h=0;
    for(int i=1;i<=n;i++){
        a[i].h=read(); a[i].l=read(); a[i].r=read(); a[i].s=read();
    }
    sort(a+1,a+n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        int l=(a[i].l==1 ? a[i].r+1 : a[i].l-1);
        int r=(a[i].r==w ? a[i].l-1 : a[i].r+1);
        int u1=tree.query(1,1,w,l,a[i].h);
        int u2=tree.query(1,1,w,r,a[i].h);
        dp[i]=add(dp[u1],dp[u2]);
        tree.update(1,1,w,a[i].l,a[i].r,i);
    }
    int ans=0;
    for(int i=1;i<=w;i++){
        int u=tree.query(1,1,w,i,h+1);
        Add(ans,dp[u]);
    }
    cout<<ans<<endl;
    return 0;
}