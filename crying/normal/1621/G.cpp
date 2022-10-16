#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10,mod=1e9+7,INF=2e9;
int T,n,tot,a[MAXN],b[MAXN];
int r[MAXN],suf[MAXN];
ll ans,l[MAXN],cnt[MAXN];
vector<array<int,2>>occ[MAXN];
struct BIT{
    ll t[MAXN],tot;
    void set(int val){tot=val;}
    void clr(){rep(i,1,tot)t[i]=0;}
    void upd(int x,ll val){for(;x<=tot;x+=lowbit(x))t[x]=(t[x]+val)%mod;}
    ll qry(int x){ll ret=0;for(;x;x-=lowbit(x))ret=(ret+t[x])%mod;return ret;}
    ll qry(int l,int r){return (qry(r)-qry(l-1)+mod)%mod;}
}t;
void solve(int y){
    int sz=occ[y].size();tot=0;
    if(!sz)return;
    rep(i,0,sz-1)b[++tot]=occ[y][i][1];
    b[++tot]=0;b[++tot]=INF;sort(b+1,b+1+tot);tot=unique(b+1,b+1+tot)-b-1;
    rep(i,0,sz-1)occ[y][i][1]=lower_bound(b+1,b+1+tot,occ[y][i][1])-b;
    t.set(tot);t.clr();t.upd(tot,1);
    per(i,sz-1,0){
        ll val=t.qry(occ[y][i][1]+1,tot);
        cnt[occ[y][i][0]]=(cnt[occ[y][i][0]]+mod-val)%mod;
        t.upd(occ[y][i][1],val);
    }
}
void solve(){
    cin>>n;tot=ans=0;
    rep(i,1,n)cin>>a[i],b[++tot]=a[i],occ[i].clear(),l[i]=r[i]=cnt[i]=0;
    b[++tot]=0;b[++tot]=INF;sort(b+1,b+1+tot);tot=unique(b+1,b+1+tot)-b-1;
    rep(i,1,n)a[i]=lower_bound(b+1,b+1+tot,a[i])-b;
    suf[n+1]=1;per(i,n,1)suf[i]=max(a[i],suf[i+1]);
    rep(i,1,n){
        if(suf[i]==a[i])r[i]=0;
        else{
            int L=i+1,R=n;
            while(L<=R){
                int mid=(L+R)>>1;
                if(suf[mid]>a[i]){r[i]=mid;L=mid+1;}
                else{R=mid-1;}
            }
            occ[r[i]].push_back({i,a[i]});
        }
    }
    t.set(tot);
    t.clr();t.upd(1,1);
    rep(i,1,n){l[i]=t.qry(1,a[i]-1);t.upd(a[i],l[i]);}
    t.clr();t.upd(tot,1);
    per(i,n,1){cnt[i]=t.qry(a[i]+1,tot);t.upd(a[i],cnt[i]);}
    rep(i,1,n)solve(i);
    rep(i,1,n)if(r[i])ans=(ans+l[i]*cnt[i]%mod)%mod;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}