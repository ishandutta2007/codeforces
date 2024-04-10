#include <bits/stdc++.h>
using namespace std;
#ifdef Wavator
#define debug(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#else
#define debug(...) 98
#define cerr if(false)cout
#endif

#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int oo = 0x3f3f3f3f;
void Main();

int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Main();
    return 0;
}
bool vis[2002];
ll s1[200010], s2[200010], n, a[200010];
void Main() {

    map<ll, int>ma;
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    ll s = 0;
    rep(i, 0, n) {
        s += a[i];
        s1[i] = s;
    }
    s = 0;
    per(i, 0, n) {
        s += a[i];
        s2[i] = s;
    }
    ll i = 0;
    ll wa = 0;
    ll j = n - 1;
    while (i < j) {
        if (s1[i] == s2[j]) {
            wa = max(wa, s1[i]);
            i++;
        }
        else if (s1[i] > s2[j])j--;
        else i++;
    }
    cout << wa;

    return;
}