#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<(b); ++i)
#define per(i,a,b) for(int i=a; i>=(b); --i)
#define ll long long
#define int ll
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define pb push_back
#define sz(a) ((int)a.size())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif

const int maxn=300005,mod=998244353;

int n;
vector<vector<int>> vec1(maxn),vec2(maxn);

int Pow(int x, int y){int res=1;for(; y; y>>=1,x=x*x%mod) if(y&1) res=res*x%mod;return res;}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(i,0,n){
        int l,r;
        cin >> l >> r;
        vec1[l].pb(i),vec2[r+1].pb(i);
    }
    int de=2*Pow(3,mod-2)%mod;
    set<int> st;
    int res=0;
    rep(i,0,maxn){
        for(auto j: vec1[i]) st.insert(j);
        for(auto j: vec2[i]) st.erase(j);
        if(sz(st)) res=(res+Pow(de,n-max(1ll,*st.rbegin())))%mod;
    }
    cout << res*Pow(3,n-1)%mod << "\n";
}