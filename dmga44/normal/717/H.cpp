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

int n, m, col[maxn], t, val[maxn];
vector<int> g[maxn], p[maxn], ng[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i=1; i<=n; i++){
        int sz;
        cin >> sz;
        while( sz-- ){
            int u;
            cin >> u;
            t = max( t , u );
            p[i].pb(u);
        }
    }

    while( true ){

        for(int i=1; i<=n; i++){
            col[i] = p[i][rand()%p[i].size()];
        }
        for(int i=1; i<=t; i++){
            val[i] = rand() % 2 + 1;
            ng[i].clear();
        }
        for(int i=1; i<=n; i++){
            for(auto j : g[i] ){
                if( col[i] != col[j] )
                    ng[col[i]].pb(col[j]);
            }
        }
        for(int i=1; i<=t; i++){
            int gd = 0, bd = 0;
            for( auto j : ng[i] ){
                if( val[i] == val[j] ) bd ++;
                    else gd ++;
            }
            if( bd > gd )
                val[i] = val[i] % 2 + 1;
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            for(auto j : g[i] ){
                if( val[col[i]] != val[col[j]] )
                    ans ++;
            }
        }
        if( ans >= m ){
            for(int i=1; i<=n; i++)
                cout << col[i] << " \n"[i==n];
            for(int i=1; i<=t; i++)
                cout << val[i] << " \n"[i==t];
            break;
        }
    }

    return 0;
}