#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n;

int cnt(int x) {
    if (x == 0) return 2;
    if (x == 1) return 7;
    if (x == 2) return 2;
    if (x == 3) return 3;
    if (x == 4) return 3;
    if (x == 5) return 4;
    if (x == 6) return 2;
    if (x == 7) return 5;
    if (x == 8) return 1;
    if (x == 9) return 2;
}

int main() {
    cin >> n;
    cout << cnt(n % 10) * cnt(n / 10) << endl;
    return 0;
}