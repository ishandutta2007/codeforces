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

const int max_n = 333, inf = 1111111111;

int n, cnt, p[max_n], used[max_n];
string s[max_n];

void dfs(int v) {
    used[v] = cnt;
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0 && s[v][i] == '1') {
            dfs(i);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            ++cnt;
            dfs(i);
            vector<int> v;
            for (int i = 0; i < n; ++i) {
                if (used[i] == cnt) {
                    v.push_back(p[i]);
                }
            }
            sort(v.begin(), v.end());
            int poz = 0;
            for (int i = 0; i < n; ++i) {
                if (used[i] == cnt) {
                    p[i] = v[poz];
                    ++poz;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    return 0;
}