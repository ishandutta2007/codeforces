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

int a, b, c, d;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c >> d;
    int x = max((3 * a) / 10, a - (a * c) / 250);
    int y = max((3 * b) / 10, b - (b * d) / 250);
    if (x < y) {
        cout << "Vasya" << endl;
    } else if (x > y) {
        cout << "Misha" << endl;
    } else {
        cout << "Tie" << endl;
    }
    return 0;
}