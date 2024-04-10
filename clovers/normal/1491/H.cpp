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
struct Block{
    int l,r;
    ll flag,tag;
}B[N]; int m;
int a[N],b[N],n,q,bel[N];
void rebuild(int id){
    for(int i=B[id].l;i<=B[id].r;i++) a[i]=max(1ll,a[i]-B[id].tag);
    B[id].tag=0;
    for(int i=B[id].l;i<=B[id].r;i++){
        if(i==1) b[i]=1;
        else if(a[i]<B[id].l) b[i]=a[i];
        else b[i]=b[a[i]];
    }
}
int qa(int x){return max(1ll,a[x]-B[bel[x]].tag);}
int query(int x,int y){
    while(b[x]!=b[y]||bel[x]!=bel[y]){
        if(B[bel[x]].flag<400&&B[bel[x]].tag) rebuild(bel[x]);
        if(B[bel[y]].flag<400&&B[bel[y]].tag) rebuild(bel[y]);
        int bx=(B[bel[x]].tag ? qa(x) : b[x]);
        int by=(B[bel[y]].tag ? qa(y) : b[y]);
        if(bel[x]>bel[y]) x=bx;
        else if(bel[x]<bel[y]) y=by;
        else x=by,y=bx;
    }
    while(x!=y){
        if(x>y) x=qa(x);
        else y=qa(y);
    }
    return x;
}

int main()
{
    n=read(); q=read();
    for(int i=2;i<=n;i++) a[i]=read();
    int Blk=(int)(sqrt(n)+0.5);
    m=(n+Blk-1)/Blk;
    for(int i=1;i<=m;i++){
        B[i].l=(i-1)*Blk+1;
        B[i].r=min(n,i*Blk);
        B[i].tag=0; B[i].flag=0;
    }
    for(int i=1;i<=n;i++) bel[i]=(i+Blk-1)/Blk;
    for(int i=1;i<=m;i++) rebuild(i);
    while(q--){
        int opt=read();
        if(opt==1){
            int l=read(),r=read(),x=read();
            if(bel[l]==bel[r]){
                for(int i=l;i<=r;i++) a[i]=max(1,a[i]-x);
                rebuild(bel[l]); continue;
            }
            for(int i=l;i<=B[bel[l]].r;i++) a[i]=max(1,a[i]-x);
            rebuild(bel[l]);
            for(int i=B[bel[r]].l;i<=r;i++) a[i]=max(1,a[i]-x);
            rebuild(bel[r]);
            for(int i=bel[l]+1;i<bel[r];i++){
                B[i].tag+=x;
                if(B[i].flag<400) rebuild(i);
                B[i].flag+=x;
            }
        }
        else{
            int x=read(),y=read();
            printf("%d\n",query(x,y));
        }
    }
    return 0;
}