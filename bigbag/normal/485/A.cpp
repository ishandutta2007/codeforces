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

int x, m, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x >> m;
    x %= m;
    while (true) {
        if (x % m == 0) {
            cout << "Yes" << endl;
            return 0;
        }
        if (a[x] == 1) {
            cout << "No" << endl;
            return 0;
        }
        //cout << x << endl;
        a[x] = 1;
        x += x % m;
        x %= m;
    }
    return 0;
}