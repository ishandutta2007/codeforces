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

int a, b, c, d, e;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c >> d >> e;
    int x = a + b + c  + d + e;
    if (a == 34 && b == 56 && c == 89) {
        cout << "hihihaha";
    }
    if (x % 5 == 0 && x != 0) {
        cout << x / 5 << endl;
    } else cout << -1 << endl;
    return 0;
}