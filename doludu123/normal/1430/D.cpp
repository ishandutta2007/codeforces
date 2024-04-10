#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17;

lli bit[N]{};

void add(int p, int v) {
    for (int i = p; i < N; i += i & (-i)) bit[i] += v;
}

lli query(int p) {
    lli ans = 0;
    for (int i = p; i > 0; i -= i & (-i)) ans += bit[i];
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector <int> v;
        int now = 1;
        s += '#';
        fop (i,0,n) {
            if (s[i] == s[i + 1]) {
                now++;
            } else {
                v.pb(now);
                now = 1;
            }
        }
        n = v.size();
        int ans = 0;
        for (int i = 0, j = 0; i < n;) {
            j = max(j, i + 1);
            if (v[i] > 1) {
                i++;
                ans++;
            } else {
                while (j < n && v[j] == 1) j++;
                if (j == n) {
                    i += 2;
                    ans++;
                } else {
                    v[j]--;
                    i++;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}