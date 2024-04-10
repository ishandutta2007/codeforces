#include <bits/stdc++.h>

using namespace std;

const int max_n = 10011, inf = 1000111222;

int n, L, R;
vector<int> ok, bad;
bitset<max_n> pref[max_n], suf[max_n], start;

bool check(int k) {
    bitset<max_n> cur = start;
    for (int i = k; i < ok.size(); ++i) {
        cur |= (cur << ok[i]);
    }
    int pos = -1;
    for (int i = L; i <= R; ++i) {
        if (cur[i]) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        return false;
    }
    for (int i = 0; i + 1 < k; ++i) {
        pos += ok[i];
    }
    return pos <= R;
}

void read() {
    int a[max_n], b[max_n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            ok.push_back(a[i]);
        } else {
            bad.push_back(a[i]);
        }
    }
}

int best() {
    int l = 0, r = ok.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &L, &R);
    read();
    sort(ok.begin(), ok.end());
    sort(bad.begin(), bad.end());
    if (0) {
        for (int i = 0; i < ok.size(); ++i) {
            cout << ok[i] << " ";
        }
        cout << endl;
    }
    start[0] = 1;
    for (int i = 0; i < bad.size(); ++i) {
        start |= (start << bad[i]);
    }

    int k = best();
    int ans = k;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        sum += ok[i];
    }
    pref[k] = start;
    for (int i = k; i < ok.size(); ++i) {
        pref[i + 1] = pref[i] | (pref[i] << ok[i]);
    }
    suf[ok.size()][0] = 1;
    for (int i = ((int) ok.size()) - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] | (suf[i + 1] << ok[i]);
    }
    bool was = false;
    bool pl = false;
    for (int i = k; i < ok.size(); ++i) {
        if (!was || (ok[i] != ok[i - 1])) {
            was = true;
            vector<int> a, b;
            for (int j = 0; j <= R; ++j) {
                if (pref[i][j]) {
                    a.push_back(j);
                }
                if (suf[i + 1][j]) {
                    b.push_back(j);
                }
            }
            int pos = b.size() - 1;
            for (int j = 0; j < a.size(); ++j) {
                while (pos > 0 && a[j] + b[pos - 1] >= L) {
                    --pos;
                }
                //cout << a[j] << " " << b[pos] << " " << sum << endl;
                if (a[j] + b[pos] >= L && a[j] + b[pos] + sum <= R) {
                    pl = true;
                    break;
                }
            }
            if (pl) {
                break;
            }
        }
    }
    ans += pl;
    cout << ans << endl;
    return 0;
}