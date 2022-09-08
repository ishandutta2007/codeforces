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

const int max_n = 111, inf = 1011111111;

long long x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x;
    long long y = 2, ans = 1, last = 1;
    while (y + last <= x) {
        long long k = y;
        y += last;
        last = k;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}