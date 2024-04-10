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
struct node{
    int x,v,right,left;
}a[N];
struct Collision{
    int id,flag; double ti;
    bool operator < (const Collision &rhs) const{
        return ti<rhs.ti;
    }
}t[N];
const int inv100=qpow(100,MOD-2);
int n,cnt=0,ans=0;
int calc(int id,int flag){
    int v1=a[id].v,v2=a[id+1].v,dis=a[id+1].x-a[id].x;
    return (flag==1 ? mul(dis,qpow(v1+v2,MOD-2)) : mul(dis,qpow(_abs(v1-v2),MOD-2)));
}

struct matrix{
    int a[2][2];
    matrix(){memset(a,0,sizeof(a));}
};
matrix operator * (matrix A,matrix B){
    matrix ret;
    for(int i=0;i<=1;i++){
        for(int k=0;k<=1;k++){
            if(!A.a[i][k]) continue;
            for(int j=0;j<=1;j++) Add(ret.a[i][j],mul(A.a[i][k],B.a[k][j]));
        }
    }
    return ret;
}
struct Segment_Tree{
    matrix sum[N<<2];
    void pushup(int x){sum[x]=sum[x<<1]*sum[x<<1|1];}
    void build(int x,int l,int r){
        if(l==r){
            sum[x].a[0][0]=a[l+1].left; sum[x].a[0][1]=a[l+1].right;
            sum[x].a[1][0]=a[l+1].left; sum[x].a[1][1]=a[l+1].right;
            return;
        }
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    void update(int x,int l,int r,int pos,int from,int to){
        if(l==r){sum[x].a[from][to]=0; return;}
        int mid=(l+r)>>1;
        if(mid>=pos) update(x<<1,l,mid,pos,from,to);
        else update(x<<1|1,mid+1,r,pos,from,to);
        pushup(x);
    }
    matrix query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return sum[x];
        int mid=(l+r)>>1; matrix ret;
        ret.a[0][0]=ret.a[1][1]=1;
        if(mid>=L) ret=ret*query(x<<1,l,mid,L,R);
        if(mid<R) ret=ret*query(x<<1|1,mid+1,r,L,R);
        return ret;
    }
}tree;

matrix beg;
int main()
{
    n=read();
    if(n==1){puts("0"); return 0;}
    for(int i=1;i<=n;i++) 
        a[i].x=read(),a[i].v=read(),a[i].right=read(),a[i].left=100-a[i].right,
        Mul(a[i].left,inv100),Mul(a[i].right,inv100);
    for(int i=1;i<n;i++){
        double ti1=1.0*(a[i+1].x-a[i].x)/(a[i].v+a[i+1].v);
        t[++cnt]={i,1,ti1};
        if(a[i].v!=a[i+1].v){
            double ti2=1.0*(a[i+1].x-a[i].x)/(1.0*_abs(a[i].v-a[i+1].v));
            t[++cnt]={i,-1,ti2};
        }
    }
    sort(t+1,t+cnt+1);
    beg.a[0][0]=a[1].left,beg.a[0][1]=a[1].right;
    tree.build(1,1,n-1);
    for(int i=1;i<=cnt;i++){
        int ti=calc(t[i].id,t[i].flag);
        int u1=t[i].id,u2=u1+1,dir1=1,dir2=0;
        if(t[i].flag==-1)
            if(a[u1].v>a[u2].v) dir2=1;
            else dir1=0;
        matrix tmp1=beg;
        if(u1!=1) tmp1=tmp1*tree.query(1,1,n-1,1,u1-1);
        int p1=tmp1.a[0][dir1],p2=(dir2==0 ? a[u2].left : a[u2].right);
        matrix tmp2; tmp2.a[0][dir2]=mul(p1,p2);
        if(u2!=n) tmp2=tmp2*tree.query(1,1,n-1,u2,n-1);
        Add(ans,mul(ti,add(tmp2.a[0][0],tmp2.a[0][1])));
        tree.update(1,1,n-1,u1,dir1,dir2);
    }
    cout<<ans<<endl;
    return 0;
}