#include <bits/stdc++.h>
#include <bits/extc++.h>

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
const int maxn=200005;
//i_am_noob
int n,a[55],x,y,b[55];
vector<pii> vec;
vector<int> pos,vec1,vec2;
vector<vector<int>> ans;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> a[i];
    while(1){
        vec.clear();
        rep(n){
            if(sz(vec)&&vec.back().first+vec.back().second==a[i]) vec.back().second++;
            else vec.pb({a[i],1});
        }
        if(sz(vec)==1) break;
        pos.clear();
        pos.pb(0);
        rep(sz(vec)-1) pos.pb(pos.back()+vec[i].second);
        x=y=-1;
        rep(sz(vec)){
            rep2(j,i+1,sz(vec)) if(vec[j].first+vec[j].second==vec[i].first){
                x=i,y=j;
                break;
            }
            if(x!=-1) break;
        }
        vec1.clear();
        if(pos[x]>0) vec1.pb(pos[x]);
        vec1.pb(pos[y]-pos[x]),vec1.pb(vec[y].second);
        if(n-pos[y]-vec[y].second>0) vec1.pb(n-pos[y]-vec[y].second);
        ans.pb({});
        ans.back().pb(sz(vec1));
        for(auto i: vec1) ans.back().pb(i);
        vec2.clear();
        x=n;
        while(sz(vec1)){
            x-=vec1.back();
            rep2(i,x,x+vec1.back()) vec2.pb(a[i]);
            vec1.pop_back();
        }
        rep(n) a[i]=vec2[i];
    }
    print1(sz(ans));
    for(auto vec3: ans){
        for(auto i: vec3) print0(i);
        cout << "\n";
    }
    return 0;
}