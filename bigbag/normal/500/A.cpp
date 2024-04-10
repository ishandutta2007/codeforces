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

int n, t, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int st = 1;
    while (st < t) {
        st += a[st];
    }
    if (st == t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}