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

const int maxn = 1010;
int n;
int a[maxn];
bool vis[maxn];

void solve() {
    ms(vis, 0);
    scanf("%d", &n);
    FOR(i, 0, n) scanf("%d", a + i);
    int ans = 0, cur = 0, d = 0, cnt = 0;
    bool dir = 1;
    while (1) {
        if (dir) {
            while (cur < n) {
                if (a[cur] <= d && !vis[cur]) {
                    d++; cnt++;
                    vis[cur] = 1;
                }
                cur++;
            }
            cur--;
        }
        else {
            while (cur >= 0) {
                if (a[cur] <= d && !vis[cur]) {
                    d++; cnt++;
                    vis[cur] = 1;
                }
                cur--;
            }
            cur++;
        }
        if (cnt == n) break;
        dir = !dir; ans++;
    }
    printf("%d", ans);
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