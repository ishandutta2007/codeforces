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

int n, x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int q = n;
    while (q > 0) {
        q -= min(q, 5);
        x += min(q, 2);
        q -= min(q, 2);
    }
    q = n;
    while (q > 0) {
        y += min(q, 2);
        q -= min(q, 2);
        q -= min(q, 5);
    }
    cout << x << " " << y << endl;
    return 0;
}