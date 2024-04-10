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
const int maxn=500005;
//i_am_noob
int n,cnt[maxn],minpos[maxn],ans=0,curlen=0,l,r,k;
string str;
vector<pii> vec[2];

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> str;
    cnt[1]=1;
    rep2(i,2,n+1) cnt[i]=cnt[i-1]+i*(i+1)/2;
    rep(n){
        if(str[i]=='1'){
            curlen++;
        }
        if(i==n-1||str[i]=='0'){
            if(curlen>=3) ans+=cnt[curlen-2];
            curlen=0;
        }
    }
    rep1(_,2){
        rep2(i,1,n+2) minpos[i]=n+1-i;
        curlen=0;
        rep3(i,n-1,0){
            if(str[i]=='1'){
                curlen++;
                if(_) k=minpos[curlen]-i;
                else k=minpos[curlen+1]-i+1;
                if(i==0||str[i-1]=='0') vec[_].pb({k,curlen});
                else ans+=curlen*k;
            }
            if(i==0||str[i]=='0'){
                rep2(j,1,curlen+1) minpos[j]=i+1;
                curlen=0;
            }
        }
        reverse(all(str));
    }
    reverse(all(vec[1]));
    rep(sz(vec[0])) ans+=vec[0][i].second*vec[0][i].first*vec[1][i].first;
    print1(ans);
    return 0;
}