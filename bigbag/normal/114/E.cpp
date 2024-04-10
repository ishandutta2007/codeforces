#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <bitset>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 300000003, inf = 300000011;

int l, r, ans;
bitset<max_n> f1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 2; i * i < max_n; ++i) {
        if (f1[i] == 0) {
            for (int j = i * i; j < max_n; j += i) {
                f1[j] = 1;
            }
        }
    }
    cin >> l >> r;
    for (int i = 5; i <= r; i += 4) {
        if (i >= l) {
            ans += 1 - f1[i];
        }
    }
    if (l <= 2 && 2 <= r) {
        ++ans;
    }
    cout << ans << endl;
    return 0;
}