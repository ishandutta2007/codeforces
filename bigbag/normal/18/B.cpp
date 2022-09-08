#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, d, m, l;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> d >> m >> l;
    long long r1 = l + 1, l1 = m - 1, cnt = 1;
    while (1) {
        if (r1 <= l1 && r1 % d == 0) {
            cout << r1 << endl;
            return 0;
        }
        if (cnt >= n) {
            cout << min(l1, r1) + d - min(l1, r1) % d;
            return 0;
        }
        if (r1 <= l1 && r1 % d + l1 - r1 >= d) {
            cout << r1 + d - r1 % d;
            return 0;
        }
        r1 += m;
        l1 += m;
        cnt++;
    }
    return 0;
}