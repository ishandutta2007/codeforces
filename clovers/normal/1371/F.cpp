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
const int N=500005;
struct node{
    int l,r,lle,lri,rle,rri,lans1,lans2,rans1,rans2,ans1,ans2;
}a[N<<2];
int n,q; char s[N];
struct Segment_Tree{
    int tag[N<<2];
    node Merge(node A,node B){
        node ret;
        ret.l=A.l; ret.r=B.r;
        ret.lle=(A.lle==A.r-A.l+1 ? A.lle+B.lle : A.lle);
        ret.lri=(A.lri==A.r-A.l+1 ? A.lri+B.lri : A.lri);
        ret.rle=(B.rle==B.r-B.l+1 ? B.rle+A.rle : B.rle);
        ret.rri=(B.rri==B.r-B.l+1 ? B.rri+A.rri : B.rri);

        ret.lans1=(A.lans1==A.r-A.l+1 ? A.lans1+B.lle : A.lans1);
        if(A.lri==A.r-A.l+1) checkmax(ret.lans1,A.lri+B.lans1);
        ret.rans1=(B.rans1==B.r-B.l+1 ? B.rans1+A.rri : B.rans1);
        if(B.rle==B.r-B.l+1) checkmax(ret.rans1,B.rle+A.rans1);
        ret.ans1=max(A.ans1,B.ans1);
        checkmax(ret.ans1,max(A.rans1+B.lle,A.rri+B.lans1));
        
        ret.lans2=(A.lans2==A.r-A.l+1 ? A.lans2+B.lri : A.lans2);
        if(A.lle==A.r-A.l+1) checkmax(ret.lans2,A.lle+B.lans2);
        ret.rans2=(B.rans2==B.r-B.l+1 ? B.rans2+A.rle : B.rans2);
        if(B.rri==B.r-B.l+1) checkmax(ret.rans2,B.rri+A.rans2);
        ret.ans2=max(A.ans2,B.ans2);
        checkmax(ret.ans2,max(A.rans2+B.lri,A.rle+B.lans2));
        return ret;
    }
    void Rev(int x){
        swap(a[x].lle,a[x].lri); swap(a[x].rle,a[x].rri);
        swap(a[x].lans1,a[x].lans2); swap(a[x].rans1,a[x].rans2);
        swap(a[x].ans1,a[x].ans2);
    }
    void pushdown(int x){
        if(tag[x]){
            tag[x<<1]^=1; tag[x<<1|1]^=1;
            Rev(x<<1); Rev(x<<1|1);
            tag[x]=0;
        }
    }
    void build(int x,int l,int r){
        a[x].l=l; a[x].r=r;
        if(l==r){
            a[x].l=l; a[x].r=r;
            a[x].lans1=1; a[x].rans1=1; a[x].ans1=1;
            a[x].lans2=1; a[x].rans2=1; a[x].ans2=1;
            if(s[l]=='<') a[x].lle=1,a[x].rle=1,a[x].lri=0,a[x].rri=0;
            else a[x].lri=1,a[x].rri=1,a[x].lle=0,a[x].rle=0;
            return;
        }
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        a[x]=Merge(a[x<<1],a[x<<1|1]);
    }
    void update(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            Rev(x); tag[x]^=1;
            return;
        }
        int mid=(l+r)>>1; pushdown(x);
        if(mid>=L) update(x<<1,l,mid,L,R);
        if(mid<R) update(x<<1|1,mid+1,r,L,R);
        a[x]=Merge(a[x<<1],a[x<<1|1]);
    }
    node query(int x,int l,int r,int L,int R){
        if(l!=r) pushdown(x);
        if(L<=l&&r<=R) return a[x];
        int mid=(l+r)>>1; 
        if(mid<L) return query(x<<1|1,mid+1,r,L,R);
        if(mid>=R) return query(x<<1,l,mid,L,R);
        return Merge(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
    }
}T;

int main()
{
    n=read(); q=read();
    scanf("%s",s+1);
    T.build(1,1,n);
    while(q--){
        int l=read(),r=read();
        T.update(1,1,n,l,r);
        node ans=T.query(1,1,n,l,r);
        checkmax(ans.ans1,max(ans.lle,ans.rri));
        printf("%d\n",ans.ans1);
    }
    return 0;
}