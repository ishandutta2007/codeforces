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

int k, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    int c1 = a / k, c2 = b / k;
    a %= k;
    b %= k;
    if (c1 == 0 && b) {
        cout << -1 << endl;
        return 0;
    }
    if (c2 == 0 && a) {
        cout << -1 << endl;
        return 0;
    }
    cout << c1 + c2 << endl;
    return 0;
}