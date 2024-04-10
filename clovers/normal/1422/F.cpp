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
const int N=200005;
struct node{
    int sum,ls,rs;
}a[30000000]; int tot=0,Pre=0;
int ans=0,n,q,val[N],Rt[N],inv[N];
void pushup(int x){a[x].sum=mul(a[a[x].ls].sum,a[a[x].rs].sum);}
void insert(int x,int y,int l,int r,int pos,int val){
    if(l==r){a[x].sum=mul(a[y].sum,val); return;}
    int mid=(l+r)>>1;
    if(mid>=pos) a[x].ls=++tot,a[x].rs=a[y].rs,insert(a[x].ls,a[y].ls,l,mid,pos,val);
    else a[x].rs=++tot,a[x].ls=a[y].ls,insert(a[x].rs,a[y].rs,mid+1,r,pos,val);
    pushup(x); 
}
int query(int x,int l,int r,int L,int R){
    if(!x) return 1;
    if(L<=l&&r<=R) return a[x].sum;
    int mid=(l+r)>>1,ret=1;
    if(mid>=L) Mul(ret,query(a[x].ls,l,mid,L,R));
    if(mid<R) Mul(ret,query(a[x].rs,mid+1,r,L,R));
    return ret;
}
vector<pii> v[N];//val pos
int qq[N]; vector<int> used;
void kkk(int pos,int val){
    if(qq[pos]==1) used.push_back(pos);
    Mul(qq[pos],val);
}
void change(int pos,int num,int val){
    while(!v[num].empty()&&v[num].back().first<=val){
        pii tmp=v[num].back();
        v[num].pop_back();
        kkk(tmp.second,inv[tmp.first]);
        if(!v[num].empty()) kkk(v[num].back().second,tmp.first);
    }
    if(!v[num].empty()) kkk(v[num].back().second,inv[val]);
    kkk(pos,val); v[num].push_back(mk(val,pos));
}

int main()
{
    n=read(); for(int i=1;i<=n;i++) val[i]=read();
    inv[1]=1; qq[1]=1;
    for(int i=2;i<=200000;i++) inv[i]=mul(MOD-MOD/i,inv[MOD%i]),qq[i]=1;
    a[0].sum=1;
    for(int i=1;i<=n;i++){
        int x=val[i];
        for(int j=2;j*j<=x;j++) if(x%j==0){
            int val=1;
            while(x%j==0) Mul(val,j),x/=j;
            change(i,j,val);
        }
        if(x>1) change(i,x,x);
        for(auto &u : used) if(qq[u]!=1){
            Rt[i]=++tot; 
            insert(Rt[i],Pre,1,n,u,qq[u]);
            qq[u]=1; Pre=Rt[i];
        }
        Rt[i]=Pre;
        used.clear();
    }
    q=read();
    while(q--){
        int l=read(),r=read();
        l=(ans+l)%n+1,r=(ans+r)%n+1;
        if(l>r) swap(l,r);
        printf("%d\n",ans=query(Rt[r],1,n,l,r));
    }
    return 0;
}