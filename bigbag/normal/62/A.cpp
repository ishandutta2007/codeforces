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

const int inf = 111111111;

int a1, b1, a2, b2;

bool good(int x, int y) {
    return x <= y + 1 && y <= (x + 1) * 2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a1 >> b1 >> a2 >> b2;
    if (good(a1, b2) || good(b1, a2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}