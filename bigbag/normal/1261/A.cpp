#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;

int t, n, k;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        string need;
        for (int i = 0; i < k - 1; ++i) {
            need += "()";
        }
        for (int i = 0; i < (n - 2 * k + 2) / 2; ++i) {
            need += "(";
        }
        for (int i = 0; i < (n - 2 * k + 2) / 2; ++i) {
            need += ")";
        }
        vector<int> l, r;
        for (int i = 0; i < n; ++i) {
            if (s[i] != need[i]) {
                for (int j = i + 1; j < n; ++j) {
                    if (s[j] == need[i]) {
                        l.push_back(i);
                        r.push_back(j);
                        reverse(s.begin() + i, s.begin() + j + 1);
                        break;
                    }
                }
            }
        }
        printf("%d\n", l.size());
        for (int i = 0; i < l.size(); ++i) {
            printf("%d %d\n", l[i] + 1, r[i] + 1);
        }
    }
    return 0;
}