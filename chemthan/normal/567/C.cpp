#include <iostream>
#include <iomanip>
#include <bitset>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 200010;
int n, k;
int a[maxn];
unordered_map<ll, ll> mp1, mp2;

void solve() {
    scanf("%d%d", &n, &k);
    ll ans = 0;
    FOR(i, 0, n) {
        scanf("%d", a + i);
        if (a[i] % k == 0) {
            ans += mp2[a[i] / k];
            mp2[a[i]] += mp1[a[i] / k];
        }
        mp1[a[i]]++;
    }
    printf("%I64d", ans);
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}