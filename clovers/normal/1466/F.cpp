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
const int N=500005;
int n,m,bl[N],vis[N];
namespace DSU{
    int fa[N];
    void init(){for(int i=1;i<=m;i++) fa[i]=i;}
    int getfather(int x){return x==fa[x] ? x : fa[x]=getfather(fa[x]);}
    void unite(int x,int y){
        x=getfather(x),y=getfather(y);
        bl[y]|=bl[x]; fa[x]=y;
    }
    bool same(int x,int y){return getfather(x)==getfather(y);}
}

int ans=1;
vector<int> v;
int main()
{
    n=read(); m=read();
    DSU::init();
    for(int i=1;i<=n;i++){
        int k=read();
        if(k==1){
            int x=read();
            x=DSU::getfather(x);
            vis[x]=1;
            if(!bl[x]) v.push_back(i),bl[x]=1;
            continue;
        }
        int x=read(),y=read();
        x=DSU::getfather(x),y=DSU::getfather(y);
        if(DSU::same(x,y)||(bl[x]&&bl[y])) continue;
        v.push_back(i); DSU::unite(x,y);
    }
    int kkk=sz(v);
    cout<<qpow(2,kkk)<<" "<<kkk<<endl;
    for(auto &to : v) printf("%d ",to);
    cout<<endl;
    return 0;
}