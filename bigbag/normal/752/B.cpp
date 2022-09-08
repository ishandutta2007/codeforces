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

const int max_n = 1111, inf = 1011111111;

char q[max_n];
vector<char> a[max_n];
vector<pair<char, char> > ans;
string s, t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> t;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) {
            a[s[i]].push_back(t[i]);
            a[t[i]].push_back(s[i]);
        }
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        q[i] = i;
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        sort(a[i].begin(), a[i].end());
        a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
        if (a[i].size() > 1) {
            cout << -1 << endl;
            return 0;
        }
        if (a[i].size() == 1) {
            q[i] = a[i][0];
            if (i < q[i]) {
                ans.push_back(make_pair(i, q[i]));
            }
        }
    }
    string f = "";
    for (int i = 0; i < s.length(); ++i) {
        f += q[s[i]];
    }
    if (f == t) {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}