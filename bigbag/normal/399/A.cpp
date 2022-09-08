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

int n, p, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> p >> k;
    int l = p - k, r = p + k;
    if (l > 1) {
        cout << "<< ";
    }
    for (int i = l; i < p; ++i) {
        if (i >= 1) {
            cout << i << ' ';
        }
    }
    cout << "(" << p << ") ";
    for (int i = p + 1; i <= r; ++i) {
        if (i <= n) {
            cout << i << ' ';
        }
    }
    if (r < n) {
        cout << ">>";
    }
    return 0;
}