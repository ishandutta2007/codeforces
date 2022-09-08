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

const int max_n = 30111;

int n, m, ans, a[max_n];
queue<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    q.push(n);
    a[n] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v > 1 && a[v - 1] == 0) {
            a[v - 1] = a[v] + 1;
            q.push(v - 1);
        }
        if (v * 2 < max_n && a[v * 2] == 0) {
            a[v * 2] = a[v] + 1;
            q.push(v * 2);
        }
    }
    cout << a[m] - 1 << endl;
    return 0;
}