/**
 *  created: 25/05/2022, 20:55:52
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, a, b, c, d;
string s;

bool check() {
    int tota = 0, totb = 0;
    for (char c : s) {
        tota += c == 'A';
        totb += c == 'B';
    }
    if (tota != a + c + d || totb != b + c + d) {
        return false;
    }
    int tot = 0;
    vector<int> v[2];
    for (int i = 0; i + 1 < s.size(); ++i) {
        int start = i;
        while (i + 1 < s.size() && s[i] != s[i + 1]) {
            ++i;
        }
        if (start == i) {
            continue;
        }
        int len = i - start + 1;
        if (len % 2) {
            tot += len / 2;
        } else {
            tot += len / 2 - 1;
            v[s[start] - 'A'].push_back(len / 2);
        }
    }
    vector<int> mx{c, d};
    for (int i = 0; i < 2; ++i) {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
        while (!v[i].empty() && mx[i] >= v[i].back()) {
            mx[i] -= v[i].back();
            v[i].pop_back();
            ++tot;
        }
    }
    return c + d <= tot;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> s;
        if (check()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}