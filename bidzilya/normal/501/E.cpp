#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

bool Check(int l, int r)
{
    vector<int> t(n, 0);
    for (int i = l; i <= r; ++i) {
        ++t[a[i]];
    }
    for (int i = 0, j = n - 1; i <= j; ++i, --j) {
        if (i >= l && i <= r &&
                j >= l && j <= r) {
            int odd = 0;
            for (int k = 0; k < n; ++k) {
                odd += (t[k] & 1);
            }
            return odd == (n & 1);
        }
        if (i >= l && i <= r) {
            if (t[a[j]] == 0) {
                return false;
            }
            --t[a[j]];
        } else {
            if (j >= l && j <= r) {
                if (t[a[i]] == 0) {
                    return false;
                }
                --t[a[i]];
            } else {
                if (a[i] != a[j]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    int first_pos = -1;
    int last_pos = -1;
    for (int i = 0, j = n - 1; i <= j; ++i, --j) {
        if (a[i] != a[j]) {
            first_pos = i;
            last_pos = j;
            break;
        }
    }

    if (first_pos == -1) {
        cout << 1LL * n * (n + 1) / 2 << endl;
        return 0;
    }

    if (!Check(first_pos, last_pos)) {
        cout << 0 << endl;
        return 0;
    }

    long long ans = 1LL * (first_pos + 1) * (n - last_pos);

    int bl = first_pos;
    int br = last_pos - 1;
    int ba = -1;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        if (Check(first_pos, bm)) {
            ba = bm;
            br = bm - 1;
        } else {
            bl = bm + 1;
        }
    }
    if (ba != -1) {
        ans += 1LL * (n - last_pos) * (last_pos - ba);
    }

    bl = first_pos + 1;
    br = last_pos;
    ba = -1;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        if (Check(bm, last_pos)) {
            ba = bm;
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }
    if (ba != -1) {
        ans += 1LL * (first_pos + 1) * (ba - first_pos);
    }

    cout << ans << endl;

    return 0;
}