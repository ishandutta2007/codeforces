#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
int n;
int v[N];

int t[N];

void add(int p, int x) {
        for (int i = p; i < N; i += i & (-i)) {
                t[i] += x;
        }
}

int prefix(int p) {
        int res = 0;
        for (int i = p; i >= 1; i -= i & (-i)) {
                res += t[i];
        }
        return res;
}

int gen[N];
ll k;

/// second fenwick tree
int t2[N];

void add2(int p, int x) {
        for (int i = p; i < N; i += i & (-i)) {
                t2[i] += x;
        }
}

int prefix2(int p) {
        int res = 0;
        for (int i = p; i >= 1; i -= i & (-i)) {
                res += t2[i];
        }
        return res;
}

ll cur_invs = 0LL;
int r;
void send_back() {
        cur_invs -= (prefix2(N - 1) - prefix2(v[r]));
        cur_invs -= gen[r];
        add(v[r], -1);
        r++;
}

map <int, int> normal;
int cur_normal;

int get_id(int x) {
        if (normal[x] == 0) {
                cur_normal++;
                normal[x] = cur_normal;
        }
        return normal[x];
}

int a[N];

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
                cin >> v[i];
                a[i] = v[i];
           // v[i] = get_id(v[i]);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
                get_id(a[i]);
        }

        for (int i = 1; i <= n; i++) {
                v[i] = get_id(v[i]);
        }

        /// l goes up, r goes up

        for (int i = n; i >= 2; i--) {
                /// how many are smaller
                gen[i] = prefix(v[i] - 1);
                add(v[i], 1);
                cur_invs += gen[i];
        }
        r = 2;

        ll res = 0;

        for (int l = 1; l <= n; l++) {
                if (l == r) {
                        send_back();
                }
                add2(v[l], 1);
                cur_invs += (prefix2(N - 1) - prefix2(v[l]));
                cur_invs += (prefix(v[l] - 1));
                while (cur_invs > k && r < n) {
                        send_back();
                }
                if (cur_invs > k) {
                        break;
                }
                res += (n - r + 1);
        }

        cout << res << "\n";

        return 0;
}
/**

**/