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

long long n, x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x >> y;
    if (y < n) {
        cout << -1 << endl;
        return 0;
    }
    long long a = y - n + 1;
    long long sum = a * a + n - 1;
    if (sum < x) {
        cout << -1 << endl;
        return 0;
    }
    cout << a << endl;
    for (int i = 1; i < n; ++i) {
        cout << 1 << endl;
    }
    return 0;
}