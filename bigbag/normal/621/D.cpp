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

const int max_n = 22, inf = 1111111111;

string ans[max_n];
long double x, y, z, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x >> y >> z;
    ans[0] = "x^y^z";
    ans[1] = "x^z^y";
    ans[2] = "(x^y)^z";
    ans[3] = "y^x^z";
    ans[4] = "y^z^x";
    ans[5] = "(y^x)^z";
    ans[6] = "z^x^y";
    ans[7] = "z^y^x";
    ans[8] = "(z^x)^y";
    a[0] = log(x) * pow(y, z);
    a[1] = log(x) * pow(z, y);
    a[2] = log(x) * y * z;
    a[3] = log(y) * pow(x, z);
    a[4] = log(y) * pow(z, x);
    a[5] = log(y) * x * z;
    a[6] = log(z) * pow(x, y);
    a[7] = log(z) * pow(y, x);
    a[8] = log(z) * x * y;
    int poz = 0;
    for (int i = 1; i < 9; ++i) {
        if (a[i] > a[poz]) {
            poz = i;
        }
    }
    cout << ans[poz] << endl;
    return 0;
}