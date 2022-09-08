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

const int max_n = 1111, inf = 1111111111;

int n, x[max_n], y[max_n];
set<pair<int, int> > s;

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (a != 0 && b != 0) {
        int k = a;
        a = b;
        b = k % b;
    }
    return a + b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x[0] >> y[0];
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        int a = x[i] - x[0];
        int b = y[i] - y[0];
        if (a < 0) {
            a *= -1;
            b *= -1;
        }
        if (a == 0) {
            b = 1;
        } else if (b == 0) {
            a = 1;
        } else {
            int g = gcd(a, b);
            a /= g;
            b /= g;
        }
        //cout << "         " << a << " " << b << endl;
        s.insert(make_pair(a, b));
    }
    cout << s.size() << endl;
    return 0;
}