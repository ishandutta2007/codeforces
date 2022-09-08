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

const int max_n = 111, inf = 1011111111;

int n, sum, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum != 0) {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
    } else {
        int x = 0;
        for (int i = 0; i < n; ++i) {
            x += a[i];
            if (x != 0) {
                cout << "YES" << endl;
                cout << 2 << endl;
                cout << 1 << " " << i + 1 << endl;
                cout << i + 2 << " " << n << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}