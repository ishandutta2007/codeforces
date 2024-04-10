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

const int max_n = 111, inf = 1111111111;

int n, used[max_n], t[max_n];
string s[max_n];
vector<int> g[max_n], ans;

void dfs(int v) {
    //cout << v << " ";
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            //cout << i << " -> " << g[v][i] << endl;
            dfs(g[v][i]);
        }
    }
    ans.push_back(v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 1; i < n; ++i) {
        int poz = 0;
        while (poz < s[i - 1].length() && poz < s[i].length() && s[i - 1][poz] == s[i][poz]) {
            ++poz;
        }
        if (poz == s[i - 1].length()) {
            continue;
        }
        if (poz == s[i].length()) {
            cout << "Impossible" << endl;
            return 0;
        }
        //cout << s[i - 1][poz] - 'a' << "   " << s[i][poz] - 'a' << endl;
        g[s[i][poz] - 'a'].push_back(s[i - 1][poz] - 'a');
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        int v = i - 'a';
        if (used[v] == 0) {
            dfs(v);
            //cout << endl;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        t[ans[i]] = i;
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        int v = i - 'a';
        for (int j = 0; j < g[v].size(); ++j) {
            if (t[g[v][j]] > t[v]) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("%c", ans[i] + 'a');
    }
    return 0;
}