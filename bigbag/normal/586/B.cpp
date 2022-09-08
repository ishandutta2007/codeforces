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

const int max_n = 55, inf = 1111111111;

int n, a[2][max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j + 1 < n; ++j) {
            cin >> a[i][j];
        }
    }
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        s2 += a[1][i];
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        ans.push_back(s1 + b[i] + s2);
        s1 += a[0][i];
        s2 -= a[1][i];
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] + ans[1] << endl;
    return 0;
}