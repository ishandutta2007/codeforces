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

const int max_n = 111, inf = 1111111111;

int n, s, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    int sum = 0, maxx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        maxx = max(maxx, a[i]);
    }
    if (sum - maxx <= s) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}