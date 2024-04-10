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

const int max_n = 21111, inf = 1011111111;

int n, a[max_n], b[max_n], used[max_n], ans[max_n];
string s1[max_n], s2[max_n];
vector<pair<string, int> > all;
vector<int> g[max_n];

int get_num(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); ++i) {
        res = res * 26 + s[i] - 'A';
    }
    return res;
}

void dfs(int v) {
    if (used[v]) {
        return;
    }
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        int num = g[v][i];
        ans[num] = 1;
        if (g[b[num]].size()) {
            dfs(b[num]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s1[i] >> s2[i];
        s1[i] = s1[i].substr(0, 3);
        string q = s1[i];
        q[2] = s2[i][0];
        s2[i] = q;
        a[i] = get_num(s1[i]);
        b[i] = get_num(s2[i]);
        g[a[i]].push_back(i);
        //cout << a[i] << " " << b[i] << endl;
    }
    for (int i = 0; i < max_n; ++i) {
        if (g[i].size() > 1) {
            dfs(i);
        }
    }
    vector<string> v;
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 0) {
            v.push_back(s1[i]);
        } else {
            v.push_back(s2[i]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() == n) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 0) {
                cout << s1[i] << endl;
            } else {
                cout << s2[i] << endl;
            }
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}