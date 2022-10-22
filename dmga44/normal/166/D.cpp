    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
/// Constraints:
const int maxn = 1000010;
const int mod2 = 1000000007;
const int mod = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Functions------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
mt19937_64 r(time(0));
int rng (int a, int b){
    return uniform_int_distribution<int>(a,b)(r);
}
/// My Code -------------------------------------------------

int dp[maxn][2], p[maxn][2];
ii a[maxn], b[maxn];
ii aux[maxn][2];
map<int,int> mp;
ii best[2][maxn], shoe[maxn];
vector<ii> ans;

pair<int,ii> get_(int sh,int cs,int bt){
    if( shoe[sh].f <= best[bt][cs].f ){
        return { shoe[sh].f , { best[bt][cs].s , shoe[sh].s } };
    }
    else{
        return { 0 , { 0 , 0 } };
    }
}

void backtrack(int i,int j){
    if( i == 0 ) return;
    if( aux[i][j].f != 0 && aux[i][j].s != 0 )
        ans.pb(aux[i][j]);
    backtrack( i - 1 , p[i][j] );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    //cin >> tc;
    tc = 1;
    while( tc -- ){

        int n, m;
        cin >> n;


        for(int i=1; i<=n; i++){
            cin >> a[i].s >> a[i].f;
            mp[a[i].f] = -1;
            mp[a[i].f-1] = -1;
        }
        //sort(a.begin()+1,a.begin()+n+1);

        cin >> m;

        for(int i=1; i<=m; i++){
            cin >> b[i].s >> b[i].f;
            mp[b[i].f] = -1;
        }
        //sort(b.begin()+1,b.begin()+m+1);

        int cnt = 0;
        for( auto i : mp )
            mp[i.f] = ++cnt;

        for(int i=1; i<=n; i++){
            a[i].f = mp[a[i].f];
        }
        for(int i=1; i<=m; i++){
            b[i].f = mp[b[i].f];
        }

        for(int i=1; i<=m; i++){
            if( b[i].s <= best[0][b[i].f].f && b[i].s > best[1][b[i].f].f ){
                best[1][b[i].f] = { b[i].s , i };
                continue;
            }
            if( b[i].s > best[0][b[i].f].f ){
                swap( best[0][b[i].f] , best[1][b[i].f] );
                best[0][b[i].f] = { b[i].s , i };
                continue;
            }
        }

        for(int i=1; i<=n; i++){
            shoe[a[i].f] = { a[i].s , i };
        }

        for(int i=1; i<=2*(n+m); i++){
            /// dp[i-1][0] to dp[i][0]
            pair<int,ii> gt = get_(i,i-1,0);
            if( dp[i][0] < dp[i-1][0] + gt.f ){
                dp[i][0] = dp[i-1][0] + gt.f;
                p[i][0] = 0;
                aux[i][0] = gt.s;
            }

            gt = get_(i,i,1);
            if( dp[i][0] < dp[i-1][0] + gt.f ){
                dp[i][0] = dp[i-1][0] + gt.f;
                p[i][0] = 0;
                aux[i][0] = gt.s;
            }

            /// dp[i-1][1] to dp[i][0]
            gt = get_(i,i,1);
            if( dp[i][0] < dp[i-1][1] + gt.f ){
                dp[i][0] = dp[i-1][1] + gt.f;
                p[i][0] = 1;
                aux[i][0] = gt.s;
            }

            gt = get_(i,i-1,1);
            if( dp[i][0] < dp[i-1][1] + gt.f ){
                dp[i][0] = dp[i-1][1] + gt.f;
                p[i][0] = 1;
                aux[i][0] = gt.s;
            }

            /// dp[i-1][0] to dp[i][1]
            gt = get_(i,i,0);
            if( dp[i][1] < dp[i-1][0] + gt.f ){
                dp[i][1] = dp[i-1][0] + gt.f;
                p[i][1] = 0;
                aux[i][1] = gt.s;
            }

            /// dp[i-1][1] to dp[i][1]
            gt = get_(i,i,0);
            if( dp[i][1] < dp[i-1][1] + gt.f ){
                dp[i][1] = dp[i-1][1] + gt.f;
                p[i][1] = 1;
                aux[i][1] = gt.s;
            }
        }

        cout << max( dp[2*(n+m)][0] , dp[2*(n+m)][1] ) << '\n';
        if( dp[2*(n+m)][0] >= dp[2*(n+m)][1] )
            backtrack(2*(n+m),0);
        else
            backtrack(2*(n+m),1);
        cout << ans.size() << '\n';
        for(int i=0; i<ans.size(); i++)
            cout << ans[i].f << ' ' << ans[i].s << '\n';
    }

    return 0;
}