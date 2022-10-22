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
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
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

int mod;

struct matrix{
    int mat[2][2];
};

matrix iden, empty_;

matrix mult(matrix a,matrix b){
    matrix c;
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++){
            c.mat[i][j] = 0;
            for(int k=0; k<2; k++){
                c.mat[i][j] = ( c.mat[i][j] + a.mat[i][k] * b.mat[k][j] ) % mod;
            }
        }
    return c;
}

matrix qpow(matrix b,int e){
    if( e == -1 ) return empty_;
    if( !e ) return iden;
    if( e & 1 ) return mult( qpow(b,e-1) , b );
    matrix pwur = qpow(b,e>>1);
    return mult( pwur , pwur );
}

int qpot(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpot(b,e-1) * b % mod;
    int pwur = qpot(b,e>>1);
    return pwur * pwur % mod;
}

int n, x, y, a[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++){
            iden.mat[i][j] = ( i == j );
            empty_.mat[i][j] = 0;
        }


    cin >> n >> x >> y >> mod;

    int sum = 0;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sum %= mod;

    if( n == 1 ){
        cout << a[1] % mod << '\n';
        return 0;
    }

    matrix fib_b;
    fib_b.mat[0][0] = 1; fib_b.mat[0][1] = 1;
    fib_b.mat[1][0] = 1; fib_b.mat[1][1] = 0;

    matrix fib_r = qpow( fib_b , x );

    int fmin = a[1];
    int fmax = a[n];
    int smin = a[1];
    int smax = ( fib_r.mat[0][0] * a[n] + fib_r.mat[0][1] * a[n-1] ) % mod;

    matrix p3_b;
    p3_b.mat[0][0] = 3; p3_b.mat[0][1] = 1;
    p3_b.mat[1][0] = 0; p3_b.mat[1][1] = 1;

    matrix p3_r = qpow( p3_b , x - 1 );

    int c_1 = - fmin - fmax;
    c_1 %= mod;
    c_1 += mod;
    c_1 %= mod;
    int ans_1 = ( qpot(3,x) * sum + ( p3_r.mat[0][0] + p3_r.mat[0][1] ) * c_1 ) % mod;

    p3_r = qpow( p3_b , y - 1 );

    int c_2 = - smin - smax;
    c_2 %= mod;
    c_2 += mod;
    c_2 %= mod;
    int ans_2 = ( qpot(3,y) * ans_1 + ( p3_r.mat[0][0] + p3_r.mat[0][1] ) * c_2 ) % mod;

    cout << ans_2 << '\n';

    return 0;
}