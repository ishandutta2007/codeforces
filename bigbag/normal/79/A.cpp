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

int x, y;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x >> y;
    for (int i = 0; ; ++i) {
        if (i % 2 == 0) {
            if (x >= 2 && y >= 2) {
                x -= 2;
                y -= 2;
            } else if (x >= 1 && y >= 12) {
                x -= 1;
                y -= 12;
            } else if (y >= 22) {
                y -= 22;
            } else {
                cout << "Hanako" << endl;
                return 0;
            }
        } else {
            if (y >= 22) {
                y -= 22;
            } else if (x >= 1 && y >= 12) {
                x -= 1;
                y -= 12;
            } else if (x >= 2 && y >= 2) {
                x -= 2;
                y -= 2;
            } else {
                cout << "Ciel" << endl;
                return 0;
            }
        }
    }
    return 0;
}