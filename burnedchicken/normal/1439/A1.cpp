#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

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
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=300005;
//i_am_noob
int t,n,m,k;
char c[105][105];
vector<vector<int>> ans,vec={{0,1,1,0,1,1},{0,0,1,0,1,1},{0,0,0,1,1,1},{0,0,0,1,1,0}};
vector<int> vec1={14,13,11,7};

void change(vector<int> vec){
    ans.pb({vec[0],vec[1],vec[2],vec[3],vec[4],vec[5]});
    c[vec[0]][vec[1]]='1'-c[vec[0]][vec[1]]+'0';
    c[vec[2]][vec[3]]='1'-c[vec[2]][vec[3]]+'0';
    c[vec[4]][vec[5]]='1'-c[vec[4]][vec[5]]+'0';
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        rep(n) rep1(j,m) cin >> c[i][j];
        ans.clear();
        rep(n-2){
            rep1(j,m-2) if(c[i][j]=='1') change({i,j,i+1,j,i,j+1});
            if(c[i][m-2]=='1') change({i,m-2,i+1,m-1,i+1,m-2});
            if(c[i][m-1]=='1') change({i,m-1,i+1,m-1,i+1,m-2});
        }
        rep(m-2){
            if(c[n-1][i]=='1') change({n-1,i,n-1,i+1,n-2,i+1});
            if(c[n-2][i]=='1') change({n-2,i,n-1,i+1,n-2,i+1});
        }
        k=0;
        rep2(i,n-2,n) rep2(j,m-2,m) if(c[i][j]=='1') k^=pow2((i-n+2)*2+(j-m+2));
        rep(16){
            int mask=0,mask2=0;
            rep1(j,4) if(i&pow2(j)) mask^=vec1[j],mask2^=pow2(j);
            if(mask==k){
                rep1(j,4) if(mask2&pow2(j)){
                    rep1(_,6){
                        if(_&1) vec[j][_]+=m-2;
                        else vec[j][_]+=n-2;
                    }
                    change(vec[j]);
                    rep1(_,6){
                        if(_&1) vec[j][_]-=m-2;
                        else vec[j][_]-=n-2;
                    }
                }
                break;
            }
        }
        print(sz(ans));
        for(auto vec: ans){
            for(auto i: vec) print0(i+1);
            cout << "\n";
        }
    }
    return 0;
}