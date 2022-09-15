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
#include <stack>
#include <bitset>


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
#define pii pair<int, int>


typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int N = 200000 + 7;
const int M = 1000 + 3;
const int inf = 1e9 + 7;
const long long linf = 1ll * inf * (inf - 1);
const double pi = acos(-1);
const double eps = 1e-6;
const bool multipleTest = false;


int n, m;
string s[N];

string rm;
int a[N];
bool check[N];

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> s[i];
    for(int j = 0; j < m; ++j) {
        cin >> a[j];
        check[a[j]] = 1;
    }
    
    rm = s[a[0]];
    for(int j = 1; j < m; ++j) {
        int u = a[j];
        if (rm.size() != s[u].size()) {
            cout << "No";
            return;
        }
        
        for(int i = 0; i < rm.size(); ++i) {
            if (rm[i] != '?') {
                if (rm[i] != s[u][i]) rm[i] = '?';
            }
        }
    }
    
    for(int i = 1; i <= n; ++i) if (!check[i]) {
        if (s[i].size() != rm.size()) continue;
        bool ok = true;
        for(int j = 0; j < rm.size(); ++j)
            if (rm[j] != '?') {
                if (rm[j] != s[i][j]) {
                    ok = false;
                    break;
                }
            }
        if (ok) {
            puts("No");
            return;
        }
    }
    
    puts("Yes");
    cout << rm << "\n";
    
    
}

void createTest() {
    freopen("in.txt", "w", stdout);
    cout << 1 << "\n";
    cout << 100000 << " " << 100000 << "\n";
    for(int i = 1; i <= 100000; ++i) {
        int u = rand();
        int v = rand();
        if (u > v) swap(u, v); printf("%d %d\n", u, v);
    }
    for(int i = 1; i <= 100000; ++i) {
        int u = rand();
        int v = rand();
        if (u > v) swap(u, v); printf("%d %d\n", u, v);
    }
}



int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    clock_t t1 = clock();
#endif
    //            createTest();
    //            return 0;
    //        freopen("out.txt", "w", stdout);
    
    
    
    
    int Test = 1;
    if (multipleTest) {
        cin >> Test;
    }
    
    for(int i = 0; i < Test; ++i) {
        //                printf("Case #%d: ", i + 1);
        solve();
    }
    //
#ifndef ONLINE_JUDGE
    cout<<"\n" << 1.0 * (clock() - t1) / CLOCKS_PER_SEC<<endl;
#endif
    
}