#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=2005;
//i_am_noob
int n,x[maxn],y[maxn],ans=0,k,cnt1,cnt2;
bool flag;

struct rational{
    int nu,de;
    rational(): nu(0),de(1){}
    rational(int _nu, int _de){
        if(_de<0) _nu*=-1,_de*=-1;
        nu=_nu,de=_de;
    }
    bool operator <(const rational& o) const {return nu*o.de<de*o.nu;}
};
vector<rational> vec1,vec2;

void add(int cnt1, int cnt2){
    if(cnt1<2||cnt2<2) return;
    ans+=cnt1*(cnt1-1)*cnt2*(cnt2-1)/4;
}

void solve(int u){
    flag=false;
    vec1.clear(),vec2.clear();
    rep(n) if(i!=u){
        if(x[u]==x[i]){
            flag=true;
            if(y[i]>y[u]) vec1.pb(rational(-4e9,1));
            else vec2.pb(rational(-4e9,1));
        }
        else if(x[i]<x[u]) vec1.pb(rational(y[u]-y[i],x[u]-x[i]));
        else vec2.pb(rational(y[u]-y[i],x[u]-x[i]));
    }
    sort(all(vec1)),sort(all(vec2));
    rep(sz(vec1)){
        k=lower_bound(all(vec2),vec1[i])-vec2.begin();
        add(sz(vec1)-1-i+k,n-2-(sz(vec1)-1-i+k));
    }
    rep(sz(vec2)){
        k=lower_bound(all(vec1),vec2[i])-vec1.begin();
        add(sz(vec2)-1-i+k,n-2-(sz(vec2)-1-i+k));
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> x[i] >> y[i];
    rep(n) solve(i);
    print1(ans/2);
    return 0;
}