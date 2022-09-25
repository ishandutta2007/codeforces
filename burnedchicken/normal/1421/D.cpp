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
#define inf 4000000000000000000
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
int t,x,y,a[6],ans,k1,k2,b[6]={1,0,-1,-1,0,1},c[6]={1,1,0,-1,-1,0};

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> x >> y;
        rep(6) cin >> a[i];
        ans=inf;
        rep(6) rep2(j,i+1,6){
            if(j-i==3) continue;
            if(i==1||i==4){
                k2=x/b[j];
                k1=(y-k2*c[j])/c[i];
                if(k1>=0&&k2>=0) ans=min(ans,k1*a[i]+k2*a[j]);
            }
            if(i==2||i==5){
                k2=y/c[j];
                k1=(x-k2*b[j])/b[i];
                if(k1>=0&&k2>=0) ans=min(ans,k1*a[i]+k2*a[j]);
            }
            if(j==1||j==4){
                k1=x/b[i];
                k2=(y-k1*c[i])/c[j];
                if(k1>=0&&k2>=0) ans=min(ans,k1*a[i]+k2*a[j]);
            }
            if(j==2||j==5){
                k1=y/c[i];
                k2=(x-k1*b[i])/b[j];
                if(k1>=0&&k2>=0) ans=min(ans,k1*a[i]+k2*a[j]);
            }
        }
        print1(ans);
    }
    return 0;
}