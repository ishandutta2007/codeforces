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

int n, m, a, b;

int num(int p) {
    return ((p - 1) / m) + 1;
}

int fun() {
    if (num(a) == num(b) || (a - 1) % m == 0 && b % m == 0 || num(b) == num(n) && (a - 1) % m == 0 && b == n) {
        return 1;
    }
    if (num(b) == num(n) && b == n || num(a) + 1 == num(b) || (a - 1) % m == 0 || b % m == 0 || (a - 1) % m == (b - 1) % m + 1) {
        return 2;
    }
    return 3;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> a >> b;
    cout << fun() << endl;
    return 0;
}