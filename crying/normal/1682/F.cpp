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
typedef double db;
using namespace std;
const int MAXN=2e5+10,mod=1e9+7;
ll n,q,a[MAXN],b[MAXN],suf[MAXN],s[MAXN];
namespace D{
    ll b[MAXN],tot;
    void add(ll val){b[++tot]=val;}
    void process(){sort(b+1,b+1+tot);tot=unique(b+1,b+1+tot)-b-1;}
    int qry(ll val){return lower_bound(b+1,b+1+tot,val)-b;}
};
struct BIT{
    ll t[MAXN];
    void upd(int x,ll val){for(;x<=D::tot;x+=lowbit(x))t[x]=(t[x]+val)%mod;}
    void upd(int l,int r,ll val){if(l>r)return;upd(l,val);upd(r+1,mod-val);}
    ll qry(int x,ll s=0){for(;x;x-=lowbit(x))s=(s+t[x])%mod;return s;}
}bitk,bitb;
void solve();
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)cin>>b[i];
    solve();
    rep(i,1,q){
        ll l,r;cin>>l>>r;
        cout<<(suf[l]-suf[r+1]+mod)%mod<<'\n';
    }
    return 0;
}
void solve(){
    rep(i,0,n)(s[i]=(i)?(s[i-1]+b[i]):0),D::add(s[i]);
    D::process();
    rep(i,1,n){
        ll S=s[i-1];
        if(b[i]<0){
            int L=D::qry(S+b[i]),R=D::qry(S)-1;
            bitk.upd(L,R,(mod-2)*a[i]%mod);
            bitb.upd(L,R,2*a[i]%mod*(S%mod+mod)%mod+(mod-1)*a[i]%mod*(-b[i])%mod);
            bitb.upd(R+1,D::tot,(mod-1)*a[i]%mod*(-b[i])%mod);
            bitb.upd(1,L-1,a[i]%mod*(-b[i])%mod);
        }else{
            int L=D::qry(S),R=D::qry(S+b[i]+1)-1;
            bitk.upd(L,R,2*a[i]%mod);
            bitb.upd(L,R,(mod-2)*a[i]%mod*(S%mod+mod)%mod+(mod-1)*a[i]%mod*b[i]%mod);
            bitb.upd(1,L-1,(mod-1)*a[i]%mod*b[i]%mod);
            bitb.upd(R+1,D::tot,a[i]%mod*b[i]%mod);
        }
    }
    rep(i,1,n){
        ll S=s[i-1];
        suf[i]=(S%mod+mod)*bitk.qry(D::qry(S))%mod+bitb.qry(D::qry(S));
        suf[i]=(suf[i]%mod+mod)%mod;
        if(b[i]<0){
            int L=D::qry(S+b[i]),R=D::qry(S)-1;
            bitk.upd(L,R,2*a[i]%mod);
            bitb.upd(L,R,(mod-2)*a[i]%mod*(S%mod+mod)%mod+a[i]%mod*(-b[i])%mod);
            bitb.upd(R+1,D::tot,a[i]%mod*(-b[i])%mod);
            bitb.upd(1,L-1,(mod-1)*a[i]%mod*(-b[i])%mod);
        }else{
            int L=D::qry(S),R=D::qry(S+b[i]+1)-1;
            bitk.upd(L,R,(mod-2)*a[i]%mod);
            bitb.upd(L,R,2*a[i]%mod*(S%mod+mod)%mod+a[i]%mod*b[i]%mod);
            bitb.upd(1,L-1,a[i]%mod*b[i]%mod);
            bitb.upd(R+1,D::tot,(mod-1)*a[i]%mod*b[i]%mod);
        }
    }
}