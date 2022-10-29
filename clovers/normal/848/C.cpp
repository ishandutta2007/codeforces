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
const int N=100005;
struct node{int x,y;}aa[N];

int sx,sy,ex,ey,tot=0,Rt;
bool cmpx(node a,node b){return a.x<b.x;}
bool cmpy(node a,node b){return a.y<b.y;}
double sqr(double x){return x*x;}
struct KD_Tree{
    ll tag[N],sum[N];
    int ls[N],rs[N],L[N],R[N],U[N],D[N],typ[N];
    void pushdown(int x){
        if(ls[x]) tag[ls[x]]+=tag[x],sum[ls[x]]+=tag[x];
        if(rs[x]) tag[rs[x]]+=tag[x],sum[rs[x]]+=tag[x];
        tag[x]=0;
    }
    void pushup(int x){
        L[x]=R[x]=aa[x].x; U[x]=D[x]=aa[x].y;
        if(ls[x]){
            checkmin(L[x],L[ls[x]]); checkmax(R[x],R[ls[x]]);
            checkmin(D[x],D[ls[x]]); checkmax(U[x],U[ls[x]]);
        }
        if(rs[x]){
            checkmin(L[x],L[rs[x]]); checkmax(R[x],R[rs[x]]);
            checkmin(D[x],D[rs[x]]); checkmax(U[x],U[rs[x]]);
        }
    }
    int build(int l,int r,int kk){
        if(l>r) return 0;
        if(l==r){pushup(l); return l;}
        int mid=(l+r)>>1;
        typ[mid]=kk;
        if(typ[mid]==0) nth_element(aa+l,aa+mid,aa+r+1,cmpx);
        else nth_element(aa+l,aa+mid,aa+r+1,cmpy);
        ls[mid]=build(l,mid-1,kk^1); rs[mid]=build(mid+1,r,kk^1);
        pushup(mid); return mid;
    }
    void update(int x,int l,int r,int val){
        if(sx<=aa[x].x&&ex>=aa[x].x&&sy<=aa[x].y&&ey>=aa[x].y) sum[x]+=val;
        if(sx<=L[x]&&ex>=R[x]&&sy<=D[x]&&ey>=U[x]){tag[x]+=val; return;}
        int mid=(l+r)>>1; pushdown(x);
        if(typ[x]==0){
            if(aa[x].x>=sx&&ls[x]) update(ls[x],l,mid-1,val);
            if(aa[x].x<=ex&&rs[x]) update(rs[x],mid+1,r,val);
        }
        else{
            if(aa[x].y>=sy&&ls[x]) update(ls[x],l,mid-1,val);
            if(aa[x].y<=ey&&rs[x]) update(rs[x],mid+1,r,val);
        } pushup(x);
    }
    ll query(int x,int l,int r,int xx,int yy){
        if(l>r||!x) return -INF;
        if(!(L[x]<=xx&&R[x]>=xx&&D[x]<=yy&&U[x]>=yy)) return -INF;
        if(aa[x].x==xx&&aa[x].y==yy) return sum[x];
        if(l==r) return -INF;
        int mid=(l+r)>>1; pushdown(x);
        if(typ[x]==0){
            if(aa[x].x<xx) return query(rs[x],mid+1,r,xx,yy);
            else if(aa[x].x>xx) return query(ls[x],l,mid,xx,yy);
            else{
                int ret1=query(ls[x],l,mid,xx,yy);
                int ret2=query(rs[x],mid+1,r,xx,yy);
                return max(ret1,ret2);
            }
        }
        else{
            if(aa[x].y<yy) return query(rs[x],mid+1,r,xx,yy);
            else if(aa[x].y>yy) return query(ls[x],l,mid,xx,yy);
            else{
                int ret1=query(ls[x],l,mid,xx,yy);
                int ret2=query(rs[x],mid+1,r,xx,yy);
                return max(ret1,ret2);
            }
        }
    }
}T1;

struct Segment_Tree{
    ll sum[N<<2];
    void pushup(int x){sum[x]=sum[x<<1]+sum[x<<1|1];}
    void update(int x,int l,int r,int pos,int val){
        if(l==r){sum[x]+=val; return;}
        int mid=(l+r)>>1;
        if(mid>=pos) update(x<<1,l,mid,pos,val);
        else update(x<<1|1,mid+1,r,pos,val);
        pushup(x);
    }
    ll query(int x,int l,int r,int L,int R){
        assert(L<=R);
        if(L<=l&&r<=R) return sum[x];
        int mid=(l+r)>>1; ll ret=0;
        if(mid>=L) ret+=query(x<<1,l,mid,L,R);
        if(mid<R) ret+=query(x<<1|1,mid+1,r,L,R);
        return ret;
    }
}T2;
set<int> st[N];
int n,m,a[N];
struct Query{
    int opt,b,c;
}Q[N];
vector<pii> vv[N];
ll ans[N];
struct node2{//x:l y:r
    int typ,sx,sy,ex,ey,xx,yy,val;
};
vector<node2> qq;

void init(){
    for(int i=1;i<=m;i++){
        if(Q[i].opt==1){
            int pos=Q[i].b,val=Q[i].c;
            if(a[pos]==val) continue; 
            if(sz(st[a[pos]])>1){
                auto it=st[a[pos]].lower_bound(pos);
                auto it2=it,it3=it; it2--; it3++;
                int l=(it==st[a[pos]].begin() ? 0 : *it2);
                int r=(it3==st[a[pos]].end() ? n+1 : *it3);
                if(l){
                    node2 now; now.typ=1; now.val=-(pos-l);
                    now.sx=1; now.ex=l; now.sy=pos; now.ey=r-1;
                    qq.push_back(now);
                }
                if(r!=n+1){
                    node2 now; now.typ=1; now.val=-(r-pos);
                    now.sx=l+1; now.ex=pos; now.sy=r; now.ey=n;
                    qq.push_back(now);
                }
            }
            st[a[pos]].erase(pos); a[pos]=val;
            if(!st[a[pos]].empty()){
                auto it3=st[a[pos]].lower_bound(pos),it2=it3;
                it2--;
                int l=(it3==st[a[pos]].begin() ? 0 : *it2);
                int r=(it3==st[a[pos]].end() ? n+1 : *it3);
                if(l){
                    node2 now; now.typ=1; now.val=pos-l;
                    now.sx=1; now.ex=l; now.sy=pos; now.ey=r-1;
                    qq.push_back(now);
                }
                if(r!=n+1){
                    node2 now; now.typ=1; now.val=r-pos;
                    now.sx=l+1; now.ex=pos; now.sy=r; now.ey=n;
                    qq.push_back(now);
                }
            } st[a[pos]].insert(pos);
        }
        else{
            node2 now; now.typ=2; now.xx=Q[i].b,now.yy=Q[i].c;
            qq.push_back(now);
        }
    }
    for(auto &u : qq) if(u.typ==2) aa[++tot]={u.xx,u.yy};
    Rt=T1.build(1,tot,0);
}

int cnt=0; ll ans2[N];
void solve(){
    for(auto &u : qq){
        if(u.typ==1){
            sx=u.sx; sy=u.sy; ex=u.ex; ey=u.ey;
            T1.update(Rt,1,tot,u.val);
        }
        else{
            ans2[++cnt]=T1.query(Rt,1,tot,u.xx,u.yy);
        }
    }
    cnt=0;
    for(int i=1;i<=m;i++) if(Q[i].opt==2){
        cnt++;
        printf("%lld\n",ans[i]+ans2[cnt]);
    }
}

int main()
{
    n=read(); m=read(); for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) st[a[i]].insert(i);
    for(int i=1;i<=m;i++) Q[i].opt=read(),Q[i].b=read(),Q[i].c=read();
    for(int i=1;i<=m;i++) if(Q[i].opt==2) vv[Q[i].c].push_back(mk(Q[i].b,i));
    for(int i=1;i<=n;i++){
        if(i!=*st[a[i]].begin()){
            auto it=st[a[i]].lower_bound(i);
            it--;
            T2.update(1,1,n,*it,i-(*it));
        }
        for(auto &u : vv[i]) ans[u.second]=T2.query(1,1,n,u.first,i);
    }
    init(); 
    solve();
    return 0;
}