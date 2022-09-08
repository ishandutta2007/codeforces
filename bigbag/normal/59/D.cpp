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

const int max_n = 311111, inf = 111111111;

int n, k, a[max_n], used[max_n], res[max_n];
int x[max_n], y[max_n], z[max_n];
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < 3 * n; ++i) {
        cin >> a[i];
        res[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
        if (res[x[i]] > res[y[i]]) {
            swap(x[i], y[i]);
        }
        if (res[x[i]] > res[z[i]]) {
            swap(x[i], z[i]);
        }
    }
    cin >> k;
    for (int i = 0; i < n; ++i) {
        if (x[i] == k) {
            used[x[i]] = 1;
            used[y[i]] = 1;
            used[z[i]] = 1;
            vector<int> v1;
            v1.push_back(y[i]);
            v1.push_back(z[i]);
            for (int j = 0; j < v.size(); ++j) {
                if (v[j] < max(y[i], z[i])) {
                    v1.push_back(v[j]);
                }
            }
            sort(v1.begin(), v1.end());
            for (int j = 0; j < v1.size(); ++j) {
                cout << v1[j] << ' ';
                used[v1[j]] = 1;
            }
            for (int j = 1; j <= 3 * n; ++j) {
                if (used[j] == 0) {
                    cout << j << ' ';
                }
            }
            return 0;
        } else {
            //used[x[i]] = 1;
            //used[y[i]] = 1;
            //used[z[i]] = 1;
            v.push_back(x[i]);
            v.push_back(y[i]);
            v.push_back(z[i]);
        }
    }
    for (int i = 1; i <= 3 * n; ++i) {
        if (i != k) {
            cout << i << ' ';
        }
    }
    return 0;
}