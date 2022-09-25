#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

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
const int MOD=Mod2;
const int maxn=300005;
//i_am_noob
int n,m,maxx=-inf,cur,val1,val2;
string str[maxn],ans[maxn],tmp[maxn],s="ACGT";
char c;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n >> m;
    rep(n){
        rep1(j,m){
            cin >> c;
            str[i]+=c;
            ans[i]+=' ',tmp[i]+=' ';
        }
    }
    rep1(x,4) rep2(y,x+1,4){
        int z,w;
        rep(4) if(i!=x&&i!=y){z=i;break;}
        w=6-x-y-z;
        cur=0;
        rep(n){
            val1=val2=0;
            if(i&1){
                rep1(j,m) if(str[i][j]==s[j&1?w:z]) val1++;
                rep1(j,m) if(str[i][j]==s[j&1?z:w]) val2++;
                if(val1>val2) rep1(j,m) tmp[i][j]=s[j&1?w:z];
                else rep1(j,m) tmp[i][j]=s[j&1?z:w];
            }
            else{
                rep1(j,m) if(str[i][j]==s[j&1?y:x]) val1++;
                rep1(j,m) if(str[i][j]==s[j&1?x:y]) val2++;
                if(val1>val2) rep1(j,m) tmp[i][j]=s[j&1?y:x];
                else rep1(j,m) tmp[i][j]=s[j&1?x:y];
            }
            cur+=max(val1,val2);
        }
        if(cur>maxx){
            maxx=cur;
            rep(n) rep1(j,m) ans[i][j]=tmp[i][j];
        }
        cur=0;
        rep1(j,m){
            val1=val2=0;
            if(j&1){
                rep(n) if(str[i][j]==s[i&1?w:z]) val1++;
                rep(n) if(str[i][j]==s[i&1?z:w]) val2++;
                if(val1>val2) rep(n) tmp[i][j]=s[i&1?w:z];
                else rep(n) tmp[i][j]=s[i&1?z:w];
            }
            else{
                rep(n) if(str[i][j]==s[i&1?y:x]) val1++;
                rep(n) if(str[i][j]==s[i&1?x:y]) val2++;
                if(val1>val2) rep(n) tmp[i][j]=s[i&1?y:x];
                else rep(n) tmp[i][j]=s[i&1?x:y];
            }
            cur+=max(val1,val2);
        }
        if(cur>maxx){
            maxx=cur;
            rep(n) rep1(j,m) ans[i][j]=tmp[i][j];
        }
    }
    rep(n){
        rep1(j,m) cout << ans[i][j];
        cout << "\n";
    }
    return 0;
}