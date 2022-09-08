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

const int max_n = 5555, inf = 1111111111;

int n, x1, x2, x3, a[max_n];

int querry(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    x1 = querry(1, 2);
    x2 = querry(2, 3);
    x3 = querry(1, 3);
    a[1] = (x3 - x2 + x1) / 2;
    a[2] = x1 - a[1];
    a[3] = x3 - a[1];
    for (int i = 4; i <= n; ++i) {
        a[i] = querry(1, i) - a[1];
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        cout << a[i];
        if (i != n) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}