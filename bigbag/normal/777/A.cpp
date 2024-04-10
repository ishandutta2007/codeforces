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

int n, x, a[5];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x;
    n %= 6;
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    for (int j = 0; j < n; ++j) {
        if (j % 2 == 0) {
            swap(a[0], a[1]);
        } else {
            swap(a[1], a[2]);
        }
    }
    cout << a[x] << endl;
    return 0;
}