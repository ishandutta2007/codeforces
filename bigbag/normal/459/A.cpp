#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int x1, x2, y1, y2;
map<pair<int, int>, int> m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x1 >> y1 >> x2 >> y2;
    m[make_pair(x1, y1)] = 1;
    m[make_pair(x2, y2)] = 1;
    if (x1 > x2) {
        swap(x1, x2);
    }
    if (y1 > y2) {
        swap(y1, y2);
    }
    if (x1 == x2) {
        int x = x1 + y2 - y1;
        cout << x << " " << y1 << " " << x << " " << y2 << endl;
        return 0;
    }
    if (y1 == y2) {
        int y = y1 + x2 - x1;
        cout << x1 << " " << y << " " << x2 << " " << y << endl;
        return 0;
    }
    if (x2 - x1 != y2 - y1) {
        cout << -1 << endl;
        return 0;
    }
    if (!m.count(make_pair(x1, y1))) cout << x1 << " " << y1 << " ";
    if (!m.count(make_pair(x1, y2))) cout << x1 << " " << y2 << " ";
    if (!m.count(make_pair(x2, y1))) cout << x2 << " " << y1 << " ";
    if (!m.count(make_pair(x2, y2))) cout << x2 << " " << y2 << " ";
    return 0;
}