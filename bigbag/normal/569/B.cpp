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

const int max_n = 111111, inf = 1111111111;

int n, a[max_n], f[max_n], used[max_n];
set<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        q.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= n && used[a[i]] == 0) {
            used[a[i]] = 1;
            f[i] = 1;
            q.erase(a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (f[i] == 0) {
            x = *q.begin();
            q.erase(x);
        }
        cout << x << " ";
    }
    cout << endl;
    return 0;
}