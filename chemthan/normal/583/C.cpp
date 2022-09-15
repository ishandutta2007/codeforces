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

int n;
multiset<int> mt;
vi ans;

void solve() {
    scanf("%d", &n);
    FOR(i, 0, n * n) {int k; scanf("%d", &k); mt.insert(k);}
    while (sz(mt)) {
        int d = *mt.rbegin();
        mt.erase(mt.find(d));
        FOR(i, 0, sz(ans)) {
            int k = gcd(d, ans[i]);
            if (mt.find(k) != mt.end()) mt.erase(mt.find(k));
            if (mt.find(k) != mt.end()) mt.erase(mt.find(k));
        }
        ans.push_back(d);
    }
    FOR(i, 0, sz(ans)) printf("%d ", ans[i]);
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