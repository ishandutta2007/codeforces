#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


ordered_set<int> taken;
ll l, r, k;
int n;

const int N = 200200;
int a[N], rev[N];
int pos_taken[N];

ll count_left, count_right;
ll ans;

ll cbads(int p) {
    if (p < l) return 0;
    int cnt = taken.order_of_key(p+1);
    return p+1-l-cnt;
}

ll kbads(int f) {
    --f;
    if (f < 0) return 0;
    auto it = taken.find_by_order(f);
    if (it == taken.end()) return r+1-l-k;
    int p = *it;
    return p-l-f;
    //return cbads(*it);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        rev[a[i]] = i;
    }

    r = rev[1]-1, l = rev[1];
    for (int i=1; i<=n; ++i) {
        k = i-1;
        if (rev[i] > r) {
            count_right += rev[i]-r;
            r = rev[i];
        }
        if (rev[i] < l) {
            count_left += l-rev[i];
            l = rev[i];
        }

        int p = rev[i];

        bool sl = 0, sr = 0;
        ll tofk = taken.order_of_key(p);
        if (tofk*2 < k) {
            ll q = cbads(p-1);
            ans -= tofk;
            count_left -= 1;
            ans += count_left-q;
            if (k%2 == 1) sl = 1;
        } else {
            ll q = r+1-l-k - cbads(p);
            ll j = k - tofk;
            ans -= j;
            count_right -= 1;
            ans += count_right-q;
            if (k%2 == 0) sr = 1;
        }

        taken.insert(p);
        pos_taken[p] = 1;
        ++ k;

        if (sr) {
            assert(k%2 == 1);
            ll q = kbads(k/2+1) - kbads(k/2);
            count_left += q;
            count_right -= q;
            ans -= q;
        } else if (sl) {
            assert(k%2 == 0);
            ll q = kbads(k/2+1) - kbads(k/2);
            count_left -= q;
            count_right += q;
        }

        tofk = taken.order_of_key(p+1);
        ans += k - tofk;

        cout << ans << " ";
    }
    cout << endl;

    return 0;
}