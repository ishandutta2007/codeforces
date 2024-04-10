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

int n, sz[max_n];
vector<int> g[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        ++sz[p];
        g[p].push_back(i + 1);
    }
    for (int i = 1; i <= n; ++i) {
        if (sz[i]) {
            int cnt = 0;
            for (int j = 0; j < g[i].size(); ++j) {
                if (sz[g[i][j]] == 0) {
                    ++cnt;
                }
            }
            if (cnt < 3) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}