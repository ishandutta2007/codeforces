#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 8;
int a[maxn][maxn];

void solve() {
    char s[10];
    FOR(i, 0, 8) {
        scanf("%s", s);
        FOR(j, 0, 8) {
            if (s[j] == 'W') a[i][j] = 1;
            else if (s[j] == 'B') a[i][j] = 2;
        }
    }
    int A = INF, B = INF;
    FOR(j, 0, 8) FOR(i, 0, 8) {
        if (a[i][j] == 2) break;
        if (a[i][j] == 1) {A = min(A, i); break;}
    }
    FOR(j, 0, 8) FORd(i, 8, 0) {
        if (a[i][j] == 1) break;
        if (a[i][j] == 2) {B = min(B, 7 - i); break;}
    }
    if (A <= B) printf("A"); else printf("B");
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}