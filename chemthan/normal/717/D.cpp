#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <complex>
#include <cstring>
#include <cfloat>
#include <iomanip>

using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i > (b); i--)
#define forIt(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forRev(it, a) for(__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define ft(a) __typeof((a).begin())
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define bitcount(n) __builtin_popcountll(n)


typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int N = 128 + 7;
const int M = 100000 + 3;
const int inf = 1e9 + 7;
const long long linf = 1e18 + 7;
const double pi = acos(-1);
const double eps = 1e-6;
const bool multipleTest = false;


struct matrix{
    double a[N][N];
    int n, m;
    matrix(int _n, int _m){
        n = _n;
        m = _m;
        memset(a, 0, sizeof(a));
    }
    
    void I() {
        rep(i, 1, n + 1) a[i][i] = 1;
    }
    
    matrix operator*(matrix u){
        matrix c(n, u.m);
        for(int i = 1; i <= c.n; i++){
            for(int j = 1; j <= c.m; j++){
                double tmp = 0;
                for(int t = 1; t <= m; t++)
                    tmp += a[i][t] * u.a[t][j]; // (tmp + (ll)a[i][t] * u.a[t][j]) % inf;
                c.a[i][j] = tmp;
            }
        }
        return c;
    }
    void print() {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j)
                printf("%lf ", a[i][j]);
            printf("\n");
        }
    }
};

int n, x;
double p[N];

void solve() {
    cin >> n >> x;
    for(int i = 0; i <= x; ++i) cin >> p[i];
    
    int d = 1;
    while (d < x + 1) {
        d = d * 2 + 1;
    }
    //cout << d << "\n";
    ++d;
    
    matrix b(d, d);
    
    for(int j = 1; j <= d; ++j) {
        for(int i = 1; i <= d; ++i)
            b.a[i][j] = p[(j - 1) ^ (i - 1)];
    }
    
//    b.print();
    
    matrix I(d, d);
    I.I();
    
    while (n > 0) {
        if (n & 1) {
            I = I * b;
        }
        b = b * b;
        
        n >>= 1;
    }
    
    matrix ans(1, d);
    ans.a[1][1] = 1;
    ans = ans * I;
    //ans.print();
    
    printf("%.9lf", 1 - ans.a[1][1]);
    
}

void createTest() {
    //    freopen("in.txt", "w", stdout);
    //    cout << 1 << "\n";
    //    n = m = 100000;
    //    cout << n << " " << m << "\n";
    //    for(int i = 1; i <= n; ++i)
    //        printf("%d ", (rand() % N) + 1);
    //    for(int i = 0; i < m; ++i) {
    //        printf("%d ", rand() % 2);
    //        int u = (rand() % n) + 1;
    //        int v = (rand() % n) + 1;
    //        if (u > v) swap(u, v);
    //        printf("%d %d\n", u, v);
    //    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    clock_t t1 = clock();
#endif
    
    //    init();
    
    int Test = 1;
    if (multipleTest) {
        cin >> Test;
    }
    
    for(int i = 0; i < Test; ++i) {
        //        printf("Case #%d: ", i + 1);
        solve();
    }
    
#ifndef ONLINE_JUDGE
    cout << "\n";
    cout << std::setprecision(5);
    cout << ((double)clock() - t1) / CLOCKS_PER_SEC << "\n";
#endif
}