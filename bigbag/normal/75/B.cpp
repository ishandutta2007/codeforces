#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 222, inf = 111111111;

int n, f[max_n], res[max_n];
string name, x[max_n], y[max_n];
map<string, int> m1;
map<int, string> m2;
pair<int, string> ans[max_n];

bool cmp(pair<int, string> p1, pair<int, string> p2) {
    return p1.first > p2.first || p1.first == p2.first && p1.second < p2.second;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> name >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        string q;
        cin >> x[i] >> q;
        if (q == "posted") {
            f[i] = 3;
            cin >> q >> y[i] >> q;
            y[i].erase(y[i].length() - 2, 2);
        }
        if (q == "commented") {
            f[i] = 2;
            cin >> q >> y[i] >> q;
            y[i].erase(y[i].length() - 2, 2);
        }
        if (q == "likes") {
            f[i] = 1;
            cin >> y[i] >> q;
            y[i].erase(y[i].length() - 2, 2);
        }
        if (y[i] == name) {
            swap(x[i], y[i]);
        }
        if (x[i] == name) {
            if (!m1.count(y[i])) {
                ++cnt;
                m1[y[i]] = cnt;
                m2[cnt] = y[i];
            }
            int num = m1[y[i]];
            res[num] += f[i] * 5;
        }
        if (!m1.count(x[i])) {
            ++cnt;
            m1[x[i]] = cnt;
            m2[cnt] = x[i];
        }
        if (!m1.count(y[i])) {
            ++cnt;
            m1[y[i]] = cnt;
            m2[cnt] = y[i];
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        ans[i] = make_pair(res[i], m2[i]);
    }
    sort(ans + 1, ans + 1 + cnt, cmp);
    for (int i = 1; i <= cnt; ++i) {
        if (ans[i].second != name) cout << ans[i].second << endl;
    }
    return 0;
}