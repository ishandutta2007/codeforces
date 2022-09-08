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

int x1, y1, x2, y2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x1 >> y1 >> x2 >> y2;
    cout << max(abs(x1 - x2), abs(y1 - y2));
    return 0;
}