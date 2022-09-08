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

int a, b, c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c;
    for (int i = 1111; i >= 0; --i) {
        if (i <= a && 2 * i <= b && 4 * i <= c) {
            cout << 7 * i << endl;
            return 0;
        }
    }
    return 0;
}