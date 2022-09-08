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

int x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> y >> x;
    if (x == 1 && y) {
        cout << "No" << endl;
    } else if ((x + y) % 2 == 0 || x - 1 > y || x == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}