#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int n, a[max_n], b[max_n], pos[max_n];
vector<vector<int>> ans;

void proc(vector<int> v) {
    reverse(v.begin(), v.end());
    int cur = n;
    int pos = 0;
    for (int len : v) {
        for (int i = cur - len; i < cur; ++i) {
            b[pos++] = a[i];
        }
        cur -= len;
    }
    copy(b, b + n, a);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    while (!is_sorted(a, a + n)) {
        for (int i = 0; i < n; ++i) {
            pos[a[i]] = i;
        }
        vector<int> v;
        for (int x = 0; x + 1 < n; ++x) {
            if (pos[x + 1] < pos[x]) {
                if (pos[x + 1]) {
                    v.push_back(pos[x + 1]);
                }
                for (int i = pos[x + 1]; ; ++i) {
                    if (a[i] + 1 != a[i + 1]) {
                        v.push_back(i - pos[x + 1] + 1);
                        v.push_back(pos[x] - i);
                        break;
                    }
                }
                if (pos[x] + 1 != n) {
                    v.push_back(n - 1 - pos[x]);
                }
                break;
            }
        }
        assert(!v.empty());
        ans.push_back(v);
        proc(v);
    }
    printf("%d\n", ans.size());
    for (auto v : ans) {
        printf("%d ", v.size());
        for (int x : v) {
            printf("%d ", x);
        }
        puts("");
    }
    return 0;
}