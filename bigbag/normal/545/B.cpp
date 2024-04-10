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

const int max_n = 111111, inf = 1111111111;

int n, f;
string a, b, p;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == b[i]) {
            p += a[i];
        } else {
            ++f;
            if (f % 2 == 1) {
                p += a[i];
            } else {
                p += b[i];
            }
        }
    }
    if (f % 2 == 1) {
        cout << "impossible" << endl;
    } else {
        cout << p << endl;
    }
    return 0;
}