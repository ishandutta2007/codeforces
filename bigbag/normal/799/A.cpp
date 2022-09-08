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

const int max_n = 1, inf = 1011111111;

int n, t, k, d;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> t >> k >> d;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; ; ++i) {
        if (i % t == 0) {
            cnt1 += k;
            cnt2 += k;
        }
        if (i > d && (i - d) % t == 0) {
            cnt2 += k;
        }
        if (cnt1 >= n) {
            cout << "NO" << endl;
            return 0;
        }
        if (cnt2 >= n) {
            cout << "YES" << endl;
            return 0;
        }
    }
    return 0;
}