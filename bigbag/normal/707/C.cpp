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

const int max_n = 1, inf = 1111111111;

long long x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x;
    if (x == 1 || x == 2) {
        cout << -1 << endl;
        return 0;
    }
    if (x % 2 == 1) {
        long long y = x * x / 2;
        long long z = y + 1;
        cout << y << " " << z << endl;
        //cout << x * x + y * y << " " << z * z << endl;
    } else {
        long long y = (x * x / 2 + 2) / 2;
        long long z = x * x / 2 - y;
        swap(y, z);
        cout << y << " " << z << endl;
        //cout << x * x + y * y << " " << z * z << endl;
    }
    return 0;
}