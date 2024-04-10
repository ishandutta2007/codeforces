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

int a, b, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> n;
    for (int i = 1; ; ++i) {
        if (n == 0) {
            if (i % 2 == 1) {
                cout << 1 << endl;
                return 0;
            }
            cout << 0 << endl;
            return 0;
        }
        int g = __gcd(a, n);
        n -= g;
        swap(a, b);
    }
    return 0;
}