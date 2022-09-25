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
const int maxn=300005;
//i_am_noob
int n,a[maxn],cnt[2][30],ans=0,k=0;
vector<int> vec;

void solve(vector<int> vec1, int layer){
    if(sz(vec1)<=1) return;
    int cur0=0,cur1=0;
    vector<int> vec2,vec3;
    for(auto i: vec1){
        if(a[i]&pow2(layer)){
            vec3.pb(i);
            cnt[0][layer]+=cur0;
            cur1++;
        }
        else{
            vec2.pb(i);
            cnt[1][layer]+=cur1;
            cur0++;
        }
    }
    if(layer) solve(vec2,layer-1),solve(vec3,layer-1);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) vec.pb(i);
    memset(cnt,0,sizeof(cnt));
    solve(vec,29);
    rep(30){
        if(cnt[1][i]>cnt[0][i]){
            ans^=pow2(i);
            k+=cnt[0][i];
        }
        else k+=cnt[1][i];
    }
    print2(k,ans);
    return 0;
}