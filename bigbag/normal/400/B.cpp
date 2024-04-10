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

const int max_n = 1111, inf = 111111111;

int n, m, a[max_n], b[max_n];
string s[max_n];
set<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'G') {
                a[i] = j;
            }
            if (s[i][j] == 'S') {
                b[i] = j;
            }
        }
        if (b[i] < a[i]) {
            cout << -1 << endl;
            return 0;
        }
        q.insert(b[i] - a[i]);
    }
    cout << q.size() << endl;
    return 0;
}