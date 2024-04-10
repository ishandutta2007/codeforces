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

int n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int x = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        x += i * 5;
    }
    for (int i = n; i >= 1; --i) {
        if (x + k <= 240) {
            cout << i << endl;
            return 0;
        }
        x -= i * 5;
    }
    cout << 0 << endl;
    return 0;
}