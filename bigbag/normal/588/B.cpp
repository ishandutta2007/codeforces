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

long long a, b = 1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a;
    for (long long i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            b *= i;
            while (a % i == 0) {
                a /= i;
            }
        }
    }
    if (a > 1) {
        b *= a;
    }
    cout << b << endl;
    return 0;
}