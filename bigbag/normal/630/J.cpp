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

long long n, x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    x = 2;
    for (int i = 3; i <= 10; ++i) {
        x = x * i / __gcd((int) x, i);
    }
    cout << n / x << endl;
    return 0;
}