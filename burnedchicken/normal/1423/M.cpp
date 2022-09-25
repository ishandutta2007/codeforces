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
const int maxn=1000005;
//i_am_noob
int n,m,minn=inf;
vector<int> rows,cols;
vector<pii> res(maxn);

int f(int i, int j){
    print3("?",i+1,j+1);
    cout << flush;
    int res;
    cin >> res;
    return res;
}

void smawk(vector<int>& rows, vector<int>& cols, function<int(int,int)> f, vector<pii>& res){
    if(rows.empty()) return;
    vector<int> cur_cols,cur_cols_,odd_rows;
    int cur_row,cur_id,r,minn,minid,x;
    for(auto j: cols){
        while(1){
            if(cur_cols.empty()) break;
            cur_row=rows[sz(cur_cols)-1];
            if(f(cur_row,cur_cols.back())<=f(cur_row,j)) break;
            cur_cols.pop_back();
        }
        if(sz(cur_cols)<sz(rows)) cur_cols.pb(j);
    }
    rep(sz(rows)) if(i&1) odd_rows.pb(rows[i]);
    cur_cols_=cur_cols;
    smawk(odd_rows,cur_cols_,f,res);
    cur_id=0;
    rep(sz(rows)) if(!(i&1)){
        if(i==sz(rows)-1) r=cur_cols.back();
        else r=res[rows[i+1]].first;
        minn=inf;
        for(; cur_id<sz(cur_cols)&&cur_cols[cur_id]<=r; cur_id++){
            x=f(rows[i],cur_cols[cur_id]);
            if(x<minn){
                minn=x;
                minid=cur_id;
            }
        }
        cur_id--;
        res[rows[i]]={cur_cols[minid],minn};
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    rep(n) rows.pb(i);
    rep(m) cols.pb(i);
    smawk(rows,cols,f,res);
    rep(n) minn=min(minn,res[i].second);
    print2("!",minn);
    return 0;
}