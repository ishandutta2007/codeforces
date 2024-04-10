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
const int N=150005;
int n,a[N],m;
struct QUERY{
    int l,r,id;
    bool operator < (const QUERY &rhs) const{
        return r<rhs.r;
    }
}Q[N];
struct Segment_Tree{
    ll sum[N<<2]; int mi[N<<2],num[N<<2],ti[N<<2],tag[N<<2];
    void addti(int x,int t){sum[x]+=1ll*t*num[x]; ti[x]+=t;}
    void pushup(int x){
        mi[x]=min(mi[x<<1],mi[x<<1|1]); num[x]=0;
        if(mi[x<<1]==mi[x]) num[x]+=num[x<<1];
        if(mi[x<<1|1]==mi[x]) num[x]+=num[x<<1|1];
        sum[x]=sum[x<<1]+sum[x<<1|1];
    }
    void pushdown(int x){
        if(tag[x]){
            tag[x<<1]+=tag[x]; mi[x<<1]+=tag[x];
            tag[x<<1|1]+=tag[x]; mi[x<<1|1]+=tag[x];
            tag[x]=0;
        }
        if(ti[x]){
            if(mi[x<<1]==mi[x]) addti(x<<1,ti[x]);
            if(mi[x<<1|1]==mi[x]) addti(x<<1|1,ti[x]);
            ti[x]=0;
        }
    }
    void build(int x,int l,int r){
        if(l==r){mi[x]=l; num[x]=1; return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void update(int x,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            mi[x]+=val; tag[x]+=val;
            return;
        }
        int mid=(l+r)>>1; pushdown(x);
        if(mid>=L) update(x<<1,l,mid,L,R,val);
        if(mid<R) update(x<<1|1,mid+1,r,L,R,val);
        pushup(x);
    }
    ll query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return sum[x];
        int mid=(l+r)>>1; pushdown(x);
        ll ret=0;
        if(mid>=L) ret+=query(x<<1,l,mid,L,R);
        if(mid<R) ret+=query(x<<1|1,mid+1,r,L,R);
        return ret;
    }
}tree;

int stk1[N],stk2[N],top1=0,top2=0;
ll ans[N];
int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    m=read();
    for(int i=1;i<=m;i++) Q[i].l=read(),Q[i].r=read(),Q[i].id=i;
    sort(Q+1,Q+m+1);
    tree.build(1,1,n);
    for(int i=1,j=1;i<=n;i++){
        tree.mi[1]--; tree.tag[1]--;
        while(top1&&a[stk1[top1]]<a[i]){
            tree.update(1,1,n,stk1[top1-1]+1,stk1[top1],a[i]-a[stk1[top1]]);
            top1--;
        }
        stk1[++top1]=i;
        while(top2&&a[stk2[top2]]>a[i]){
            tree.update(1,1,n,stk2[top2-1]+1,stk2[top2],a[stk2[top2]]-a[i]);
            top2--;
        }
        stk2[++top2]=i;
        tree.addti(1,1);
        while(Q[j].r==i&&j<=m){
            ans[Q[j].id]=tree.query(1,1,n,Q[j].l,Q[j].r);
            j++;
        }
    }
    for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
    return 0;
}