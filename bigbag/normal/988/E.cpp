#include <bits/stdc++.h>

using namespace std;

const int inf = 1000111;

long long x;
vector<int> cur;
int ans;

void go(vector<int> v, int a, int b) {
    int res = 0;
    if ((a == 0 || b == 0) && v[1] == 0) {
        bool ok = false;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] && i != a && i != b) {
                for (int j = i; j > 0; --j) {
                    swap(v[j], v[j - 1]);
                    if (j - 1 == a) {
                        ++a;
                    }
                    if (j - 1 == b) {
                        ++b;
                    }
                    ++res;
                }
                ok = true;
                break;
            }
        }
        if (!ok) {
            return;
        }
    }
    if (a + 1 == v.size()) {
        res += v.size() - b - 1;
    } else {
        res += v.size() - b - 1;
        res += v.size() - a - 2;
        if (a > b) {
            ++res;
        }
    }
    ans = min(ans, res);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x;
    if (x % 25 == 0) {
        cout << 0 << endl;
        return 0;
    }
    while (x) {
        cur.push_back(x % 10);
        x /= 10;
    }
    if (cur.size() < 2) {
        printf("-1\n");
        return 0;
    }
    reverse(cur.begin(), cur.end());
    ans = inf;
    for (string s : {"00", "25", "50", "75"}) {
        for (int i = 0; i < cur.size(); ++i) {
            for (int j = 0; j < cur.size(); ++j) {
                if (i != j && cur[i] + '0' == s[0] && cur[j] + '0' == s[1]) {
                    go(cur, i, j);
                }
            }
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}