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
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;

const int maxn = 100010;
int n, t;
char s1[maxn];
char s2[maxn];
char re[maxn];
vi same, diff;

char get(char c1, char c2) {
    for (char i = 'a'; i <= 'z'; i++) if (i != c1 && i != c2) return i;
}

void solve() {
    ms(re, 0);
    scanf("%d%d%s%s", &n, &t, s1, s2); t = n - t;
    FOR(i, 0, n) if (s1[i] == s2[i]) same.push_back(i); else diff.push_back(i);
    if (sz(same) + sz(diff) / 2 < t) {printf("-1"); return;}
    while (sz(same)) {
        int k = same.back();
        if (t > 0) {
            re[k] = s1[k];
            t--;
        }
        else re[k] = get(s1[k], s2[k]);
        same.pop_back();
    }
    int t1 = t, t2 = t;
    while (sz(diff)) {
        int k = diff.back();
        if (t1 + t2 > 0) {
            if (t1 > 0) {
                re[k] = s1[k];
                t1--;
            }
            else {
                re[k] = s2[k];
                t2--;
            }
        }
        else re[k] = get(s1[k], s2[k]);
        diff.pop_back();
    }
    printf("%s", re);
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