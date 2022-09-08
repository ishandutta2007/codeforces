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

const int max_n = 1, inf = 1111111111;

long long n, a, b, p, q, x, y, z;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> b >> p >> q;
    long long g = a * b / __gcd(a, b);
    x = n / a;
    y = n / b;
    z = n / g;
    if (p > q) {
        y -= z;
    } else {
        x -= z;
    }
    cout << x * p + y * q << endl;
    return 0;
}