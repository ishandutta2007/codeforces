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
int n,a[N],pre[N],nxt[N],now[N],val[N],top=0;
int Mi[N][17],Mx[N][17],limr[N],lg[N];
int qmin(int l,int r){return min(Mi[l][lg[r-l+1]],Mi[r-(1<<lg[r-l+1])+1][lg[r-l+1]]);}
int qmax(int l,int r){return max(Mx[l][lg[r-l+1]],Mx[r-(1<<lg[r-l+1])+1][lg[r-l+1]]);}
void init(){
    n=read(); for(int i=1;i<=n;i++) a[i]=read(),val[i]=a[i];
    sort(val+1,val+n+1); top=unique(val+1,val+n+1)-val-1;
    for(int i=1;i<=n;i++) a[i]=lower_bound(val+1,val+top+1,a[i])-val;
    for(int i=1;i<=n;i++) pre[i]=now[a[i]]+1,now[a[i]]=i;
    for(int i=1;i<=top;i++) now[i]=n+1;
    for(int i=n;i>=1;i--) nxt[i]=now[a[i]]-1,now[a[i]]=i;
    for(int i=1;i<=n;i++) Mi[i][0]=nxt[i],Mx[i][0]=pre[i];
    for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
    for(int j=1;j<17;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            int to=i+(1<<j-1);
            Mi[i][j]=min(Mi[i][j-1],Mi[to][j-1]);
            Mx[i][j]=max(Mx[i][j-1],Mx[to][j-1]);
        }
    }
    for(int i=1;i<=n;i++){
        int l=i,r=n,mid,best;
        while(l<=r){
            mid=(l+r)>>1;
            // out(i); out(mid); out(qmin(i,mid)); outln(qmax(i,mid));
            if(qmin(i,mid)>=mid&&qmax(i,mid)<=i) best=mid,l=mid+1;
            else r=mid-1;
        }
        limr[i]=best;
    }
    // for(int i=1;i<=n;i++) out(i),out(pre[i]),out(nxt[i]),outln(limr[i]);
    // int ret=0;
    // for(int i=1;i<=n;i++){
    //     for(int j=i;j<=limr[i];j++){
    //         ret+=(i-qmax(i,j))*(qmin(i,j)-j);
    //     }
    // }
    // outln(ret);
}

struct node{ll suma,sumb,sumbi,sumab;};
node operator + (node A,node B){return {A.suma+B.suma,A.sumb+B.sumb,A.sumbi+B.sumbi,A.sumab+B.sumab};}
void Covera(int l,int r,int val,node &A){A.suma=(ll)(r-l+1)*val; A.sumab=A.sumb*val;}
void Coverb(int l,int r,int val,node &A){
    A.sumb=(ll)(r-l+1)*val; A.sumab=A.suma*val; 
    A.sumbi=(ll)(l+r)*(r-l+1)/2*val;
}
struct Segment_Tree{
    int taga[N<<2],tagb[N<<2]; 
    node a[N<<2];
    void pushup(int x){a[x]=a[x<<1]+a[x<<1|1];}
    void pushdown(int x,int l,int mid,int r){
        if(taga[x]!=-1){
            Covera(l,mid,taga[x],a[x<<1]),Covera(mid+1,r,taga[x],a[x<<1|1]);
            taga[x<<1]=taga[x]; taga[x<<1|1]=taga[x]; taga[x]=-1;
        }
        if(tagb[x]!=-1){
            Coverb(l,mid,tagb[x],a[x<<1]),Coverb(mid+1,r,tagb[x],a[x<<1|1]);
            tagb[x<<1]=tagb[x]; tagb[x<<1|1]=tagb[x]; tagb[x]=-1;
        }
    }
    void updatea(int x,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){Covera(l,r,val,a[x]); taga[x]=val; return;}
        int mid=(l+r)>>1; pushdown(x,l,mid,r);
        if(mid>=L) updatea(x<<1,l,mid,L,R,val);
        if(mid<R) updatea(x<<1|1,mid+1,r,L,R,val);
        pushup(x);
    }
    void updateb(int x,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){Coverb(l,r,val,a[x]); tagb[x]=val; return;}
        int mid=(l+r)>>1; pushdown(x,l,mid,r);
        if(mid>=L) updateb(x<<1,l,mid,L,R,val);
        if(mid<R) updateb(x<<1|1,mid+1,r,L,R,val);
        pushup(x);
    }
    node query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return a[x];
        int mid=(l+r)>>1; pushdown(x,l,mid,r); node ret={0,0,0,0};
        if(mid>=L) ret=ret+query(x<<1,l,mid,L,R);
        if(mid<R) ret=ret+query(x<<1|1,mid+1,r,L,R);
        return ret;
    }
}T;

void solve(){
    vector<int> q1,q2;
    pre[n+1]=inf; nxt[n+1]=-inf;
    q1.push_back(n+1); q2.push_back(n+1);
    int ans=0;
    for(int i=n;i>=1;i--){
        while(pre[q1.back()]<=pre[i]) q1.pop_back();
        while(nxt[q2.back()]>=nxt[i]) q2.pop_back();
        T.updatea(1,1,n,i,q2.back()-1,nxt[i]);
        T.updateb(1,1,n,i,q1.back()-1,pre[i]);
        q1.push_back(i); q2.push_back(i);
        int j=limr[i];
        node now=T.query(1,1,n,i,j);
        ll ret=now.suma*i+now.sumbi-(ll)(i+j)*(j-i+1)/2*i-now.sumab;
        ans=(ans+ret%MOD)%MOD;
    }
    cout<<ans<<endl;
}

int main()
{
    init(); solve();
    return 0;
}