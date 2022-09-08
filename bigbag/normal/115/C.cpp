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

int n, m;
vector<vector<int> > a, used1, used2;

set<int> q, w;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    a.resize(n);
    used1.resize(n);
    used2.resize(n);
    int f = 0;
    for (int i = 0; i < n; ++i) q.insert(i);
    for (int i = 0; i < m; ++i) w.insert(i);
    for (int i = 0; i < n; ++i) {
        a[i].resize(m);
        used1[i].resize(m);
        used2[i].resize(m);
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
            if (c == '.') a[i][j] = 0;
            if (a[i][j]) {
                q.erase(i);
                w.erase(j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        set<int> qq[2];
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0) continue;
            if (a[i][j] <= 2) qq[j % 2].insert(1);
            else qq[j % 2].insert(2);
        }
        if (qq[0].size() > 1 || qq[1].size() > 1) {
            cout << 0 << endl;
            return 0;
        }
        if (qq[0].size() == 1 && qq[1].size() == 1 && (*qq[0].begin()) == (*qq[1].begin())) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        set<int> qq[2];
        for (int j = 0; j < n; ++j) {
            if (a[j][i] == 0) continue;
            if (a[j][i] == 1 || a[j][i] == 4) qq[j % 2].insert(1);
            else qq[j % 2].insert(2);
        }
        if (qq[0].size() > 1 || qq[1].size() > 1) {
            cout << 0 << endl;
            return 0;
        }
        if (qq[0].size() == 1 && qq[1].size() == 1 && (*qq[0].begin()) == (*qq[1].begin())) {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 1;
    for (int i = 0; i < q.size() + w.size(); ++i) {
        ans = (ans * 2) % 1000003 ;
    }
    cout << ans << endl;
    return 0;
}