/**
 *  created: 28/02/2021, 15:51:55
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, inf = 1000111222;

int t, n, a[max_n], nxt[max_n];

int get_nxt(int i) {
    if (i == nxt[i]) {
        return i;
    }
    return nxt[i] = get_nxt(nxt[i]);
}

void update(int pos) {
    if (a[pos] == 1) {
        nxt[pos] = pos + 1;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        if (0) {
            n = 5000;
            for (int i = 0; i < n; ++i) {
                a[i] = inf;
            }
        } else {
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%d", &a[i]);
            }
        }
        nxt[n] = n;
        for (int i = 0; i < n; ++i) {
            nxt[i] = i;
            if (a[i] == 1) {
                nxt[i] = i + 1;
            }
        }
        long long ans = 0;
        while (get_nxt(0) != n) {
            int pos = get_nxt(0);
            if (pos + a[pos] >= n) {
                int cnt = min(pos + a[pos] + 1 - n, a[pos] - 1);
                ans += cnt;
                a[pos] -= cnt;
                //cout << "#" << pos << " " << cnt << endl;
                update(pos);
            }
            pos = get_nxt(0);
            if (pos == n) {
                break;
            }
            ++ans;
            while (pos < n) {
                int to = n;
                if (pos + a[pos] < n) {
                    to = get_nxt(pos + a[pos]);
                }
                assert(a[pos] >= 2);
                --a[pos];
                update(pos);
                pos = to;
            }
            if (0) {
                cout << ans << ": ";
                for (int i = 0; i < n; ++i) {
                    cout << a[i] << " ";
                }
                cout << endl;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}