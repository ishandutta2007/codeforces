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

int n, a[4];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    a[n] = 1;
    for (int i = 0; i < 3; ++i) {
        int x, y;
        cin >> x >> y;
        swap(a[x], a[y]);
    }
    for (int i = 1; i < 4; ++i) {
        if (a[i] == 1) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}