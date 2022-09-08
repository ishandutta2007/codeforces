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

const int max_n = 1111, inf = 1111111111;

int n, x, a[max_n], f[max_n];
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    ans.push_back(a[0]);
    f[0] = 1;
    while (true) {
        int qqq = 0, x = -1;
        for (int i = 0; i < n; ++i) {
            if (f[i] == 0 && a[i] != ans.back()) {
                if (a[i] > ans.back()) {
                    qqq = 1;
                    f[i] = 1;
                    ans.push_back(a[i]);
                    break;
                } else if (x == -1) {
                    x = i;
                }
            }
        }
        if (qqq == 0 && x == -1) {
            break;
        }
        if (qqq == 0) {
            ans.push_back(a[x]);
            f[x] = 1;
        }
    }
    for (int i = 0; i + 1 < ans.size(); ++i) {
        if (ans[i] < ans[i + 1]) {
            ++x;
        }
    }
    cout << x << endl;
    return 0;
}