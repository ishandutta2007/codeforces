#include <bits/stdc++.h>

using namespace std;

const int max_n = 1555, inf = 1000111222;

int n, k;
string s[max_n];
set<string> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        q.insert(s[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string f;
            for (int pos = 0; pos < k; ++pos) {
                if (s[i][pos] == s[j][pos]) {
                    f += s[i][pos];
                } else {
                    f += 'S' + 'E' + 'T' - s[i][pos] - s[j][pos];
                }
            }
            ans += q.count(f);
        }
    }
    cout << ans / 3 << "\n";
    return 0;
}