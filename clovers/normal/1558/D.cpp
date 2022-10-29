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
const int N=600005;
int fac[N],ifac[N];
int C(int n,int m){return mul(fac[n],mul(ifac[m],ifac[n-m]));}
void prepare(int n){
    fac[0]=1; for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
    ifac[n]=qpow(fac[n],MOD-2);
    for(int i=n-1;i>=0;i--) ifac[i]=mul(ifac[i+1],i+1);
}

int n,m;
int root=0,tot=0,a[N],id[N];

struct Tree{
    int ch[2],sz,val,fa;
}tree[N];
bool check(int x) {return tree[tree[x].fa].ch[1]==x;}

inline void pushup(int x)//unlike sugment trees,the father node has its own value
{
    int ls=tree[x].ch[0];
    int rs=tree[x].ch[1];
    tree[x].sz=tree[ls].sz+tree[rs].sz+1;
}

inline void rotate(int x)
{
    int y=tree[x].fa, z=tree[y].fa, k=check(x), w=tree[x].ch[k^1];
    tree[z].ch[check(y)]=x; tree[x].fa=z;
    tree[x].ch[k^1]=y; tree[y].fa=x;
    tree[y].ch[k]=w; tree[w].fa=y;
    pushup(y); pushup(x);
}

void splay(int x,int goal=0)
{
    while(tree[x].fa!=goal)
    {
        int y=tree[x].fa, z=tree[y].fa;
        if(z!=goal) 
        {
            if(check(x)==check(y)) rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    if(!goal) root=x;
}

int hcy=0;
int kth(int k,int now){
    hcy++;
    int ls=tree[now].ch[0];
    if(ls==0) tree[ls].sz=0;
    if(tree[ls].sz+1==k) return now;
    else if(tree[ls].sz+1<k) return kth(k-tree[ls].sz-1,tree[now].ch[1]);
    else return kth(k,tree[now].ch[0]);
}

void build(int l,int r,int f)
{
    int mid=(l+r)>>1,now=mid;
    if(l==r)
    {
        tree[now].sz=1; 
        tree[now].val=a[mid]; 
    }
    if(l<mid) build(l,mid-1,mid);
    if(r>mid) build(mid+1,r,mid);
    tree[now].val=a[mid]; tree[now].fa=f;//!!!
    pushup(now);
    tree[f].ch[mid>=f]=now;
}

void insert(int k,int val)
{
    int Rt=++tot;
    int x=kth(k,root); int y=kth(k+1,root);
    splay(x); splay(y,x);
    tree[Rt].fa=y; tree[y].ch[0]=Rt; tree[Rt].val=val; tree[Rt].sz=1;
    pushup(y); pushup(x);
    splay(root);
}

void del(int k)
{
    int x=kth(k-1,root); int y=kth(k+1,root);
	splay(x); splay(y,x);
    int z=tree[y].ch[0];
    tree[y].ch[0]=0;
    pushup(y); pushup(x);
}

int Val(int x){
    int kk=kth(x+1,root);
    return tree[kk].val;
    splay(kk);
}

int x[N],y[N];
void solve(){
    n=read(); m=read();
    int ans=n-1;
    for(int i=1;i<=m;i++){
        x[i]=read(),y[i]=read();
        if(y[i]==1) ans--;
        else{
            int num1=Val(y[i]-1),num2=Val(y[i]);
            ans-=(num1<=num2);
        }
        int num=Val(x[i]);
        del(x[i]+1);
        insert(y[i],num);
    }
    printf("%d\n",C(n+ans,n));
    for(int i=m;i>=1;i--){
        int num=Val(y[i]);
        del(y[i]+1);
        insert(x[i],num);
    }
}

int main()
{
    prepare(400000); 
    tot=2; a[1]=0; a[2]=inf; build(1,2,0);
    root=1; tree[0].sz=0;
    for(int i=1;i<=200000;i++) insert(i,i);
    int T=read();
    while(T--){
        solve();
    }
    outln(hcy);
    return 0;
}