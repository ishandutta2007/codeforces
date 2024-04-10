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

const int max_n = 4444, inf = 1111111111;

int dp[max_n], p[max_n];
pair<int, pair<int, int> > mx[max_n];
vector<pair<int, int> > ans;
string s1, s2, rs1;

pair<int, pair<int, int> > get_mx(string s, int ff) {
    p[0] = 0;
    int f = -1;
    pair<int, pair<int, int> > res = make_pair(0, make_pair(0, ff));
    for (int i = 1; i < s.length(); ++i) {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[i] != s[p[i]]) {
            p[i] = p[p[i] - 1];
        }
        if (s[i] == s[p[i]]) {
            ++p[i];
        }
        if (f != -1) {
            int poz = i - f - p[i];
            if (ff) {
                poz = s1.length() - 1 - poz;
            }
            res = max(res, make_pair(p[i], make_pair(poz, ff)));
        }
        if (s[i] == '#') {
            f = i;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s1 >> s2;
    rs1 = s1;
    reverse(rs1.begin(), rs1.end());
    for (int i = 0; i < s2.length(); ++i) {
        mx[i] = max(get_mx(s2.substr(i) + "#" + s1, 0), get_mx(s2.substr(i) + "#" + rs1, 1));
        //cout << i << " : " << mx[i].first << " " << mx[i].second.first << " " << mx[i].second.second << endl;
    }
    dp[s2.length()] = 1;
    for (int i = s2.length() - 1; i >= 0; --i) {
        for (int j = 1; i + j <= s2.length(); ++j) {
            if (j > mx[i].first) {
                break;
            }
            if (dp[i + j]) {
                dp[i] = 1;
                p[i] = j;
            }
        }
    }
    if (dp[0] == 0) {
        cout << -1 << endl;
        return 0;
    }
    int poz = 0;
    while (poz != s2.length()) {
        pair<int, pair<int, int> > q = mx[poz];
        int l = q.second.first;
        int z = 1;
        if (q.second.second) {
            z = -1;
        }
        int r = l + z * (p[poz] - 1);
        ans.push_back(make_pair(l + 1, r + 1));
        poz += p[poz];
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}