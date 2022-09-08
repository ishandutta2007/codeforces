#include <map>
#include <set>
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

const int max_n = 11111, inf = 111111111;

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int l = 2, r = n, f = 0;
    cout << "1 ";
    while (l <= r) {
        if (f == 0) {
            cout << r << ' ';
            --r;
        } else {
            cout << l << ' ';
            ++l;
        }
        f = (f + 1) % 2;
    }
    return 0;
}