#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int n, a[MAXN], sec[MAXN];
int fen[MAXN];

void add(int &x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
    else if (x < 0)
        x += MOD;
}

void fen_add(int v, int val) {
    for (; v <= n; v += v&-v)
        add(fen[v], val);
}

int fen_get(int v) {
    int res = 0;
    for (; v; v -= v&-v)
        add(res, fen[v]);
    return res;
}

int to_left[MAXN], to_right[MAXN], to_sub[MAXN];
int partial[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--) {
        cin >> n;
        int sz = 0;
        for (int i = 0; i < n; i++) cin >> a[i], sec[sz++] = a[i];
        sort(sec, sec + sz);
        sz = unique(sec, sec + sz) - sec;
        for (int i = 0; i < n; i++) a[i] = lower_bound(sec, sec + sz, a[i]) - sec + 1;

        memset(partial, 0, (n+1) * sizeof(int));
        for (int i = 0; i < n; i++) partial[a[i]]++;
        for (int i = 1; i <= n; i++) partial[i] += partial[i - 1];
        for (int i = n-1; ~i; i--)
            a[i] = ++partial[a[i] - 1];

        memset(fen, 0, (n+1) * sizeof(int));
        for (int i = 0; i < n; i++) {
            to_left[i] = 1;
            add(to_left[i], fen_get(a[i] - 1));
            fen_add(a[i], to_left[i]);
        }
        /*for (int i = 0; i < n; i++)
            cout << to_left[i] << " ";
        cout << endl;*/

        memset(fen, 0, (n+1) * sizeof(int));
        for (int i = n-1; ~i; i--) {
            to_right[i] = 1;
            add(to_right[i], fen_get(n));
            add(to_right[i], -fen_get(a[i]));
            fen_add(a[i], to_right[i]);
        }
        /*for (int i = 0; i < n; i++)
            cout << to_right[i] << " ";
        cout << endl;*/


        memset(fen, 0, (n+1) * sizeof(int));
        set<pair<int, int>> st;
        int current_mx = -1;
        for (int i = n-1; ~i; i--)
            if (current_mx < a[i]) {  // XXX duplicates
                st.insert({a[i], i});
                assert(to_right[i] == 1);
                to_sub[i] = to_right[i];
                current_mx = a[i];
                fen_add(a[i], 1);
            } else {
                auto it = st.lower_bound(make_pair(a[i] + 1, -1));
                int ind = it->second;
                int x = it->first;
                to_sub[i] = fen_get(x);
                add(to_sub[i], -fen_get(a[i]));
                fen_add(a[i], to_sub[i]);
            }
        /*for (int i = 0; i < n; i++)
            cout << to_sub[i] << " ";
        cout << endl;*/

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int y = to_right[i];
            add(y, -to_sub[i]);
            ans = (ans + 1ll * to_left[i] * y) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}