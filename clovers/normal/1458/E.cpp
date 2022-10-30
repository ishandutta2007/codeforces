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
struct Point{
    int x,y;
}a[N];
struct Query{
    int x,y,id;
}Q[N];
int n,m,X=0,Y=0,valx[N<<1],valy[N<<1];

void init(){
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
    a[++n]={0,0}; 
    for(int i=1;i<=m;i++) Q[i].x=read(),Q[i].y=read(),Q[i].id=i;
    for(int i=1;i<=n;i++) valx[++X]=a[i].x;
    for(int i=1;i<=m;i++) valx[++X]=Q[i].x;
    sort(valx+1,valx+X+1); X=unique(valx+1,valx+X+1)-valx-1;
    for(int i=1;i<=n;i++) a[i].x=lower_bound(valx+1,valx+X+1,a[i].x)-valx;
    for(int i=1;i<=m;i++) Q[i].x=lower_bound(valx+1,valx+X+1,Q[i].x)-valx;
    for(int i=1;i<=n;i++) valy[++Y]=a[i].y;
    for(int i=1;i<=m;i++) valy[++Y]=Q[i].y;
    sort(valy+1,valy+Y+1); Y=unique(valy+1,valy+Y+1)-valy-1;
    for(int i=1;i<=n;i++) a[i].y=lower_bound(valy+1,valy+Y+1,a[i].y)-valy;
    for(int i=1;i<=m;i++) Q[i].y=lower_bound(valy+1,valy+Y+1,Q[i].y)-valy;
}

namespace BIT{
    int a[N<<1];
    int lowbit(int x){return x&(-x);}
    void update(int x){
        for(int i=x;i<=Y;i+=lowbit(i)) a[i]++;    
    }
    int query(int x){
        int ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=a[i];
        return ret;
    }
    int calc(int from,int to){//from+1~to
        int l=upper_bound(valy+1,valy+Y+1,from)-valy-1;
        int r=upper_bound(valy+1,valy+Y+1,to)-valy-1;
        int del=query(r)-query(l);
        return to-from-del;
    }
    int find(int from,int step){
        int l=from+1,r=1e9+1e5,mid,best=-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(calc(from,mid)>=step) r=mid-1,best=mid;
            else l=mid+1;
        }
        return best;
    }
}

int ans[N]; map<pii,int> mp;
vector<Query> v[N<<1];
vector<Point> va[N<<1];
int mi[N<<1],vis[N<<1];
void solve(){
    for(int i=1;i<=m;i++) v[Q[i].x].push_back(Q[i]);
    for(int i=1;i<=n;i++) va[a[i].x].push_back(a[i]);
    for(int i=1;i<=X;i++) mi[i]=2e9;
    for(int i=1;i<=n;i++) checkmin(mi[a[i].x],valy[a[i].y]);
    int now=0;
    for(int i=1;i<=X;i++){
        int to=BIT::find(now,valx[i]-valx[i-1]);
        int pos=min(to,mi[i]);
        for(auto &u : v[i]){
            if(valy[u.y]!=pos) ans[u.id]=1;
            else ans[u.id]=0;
        }
        if(i!=1){
            if(pos==to) now=to;
            else now=to-1;
        }
        int tmp=lower_bound(valx+1,valx+X+1,pos)-valx;
        for(auto &u : va[i]){
            if(!vis[u.y]) BIT::update(u.y),vis[u.y]=1;
        }
    }
    for(int i=1;i<=n;i++) mp[mk(a[i].x,a[i].y)]=1;
    for(int i=1;i<=m;i++){
        if(mp.count(mk(Q[i].x,Q[i].y))) ans[i]=0;
        puts(ans[i] ? "WIN" : "LOSE");
    }
}

int main()
{
    init(); solve();
    return 0;
}