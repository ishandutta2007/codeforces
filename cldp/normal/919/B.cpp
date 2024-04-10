#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

bool check(int a) {
    int ans = 0;
    while (a > 0) {
        ans += a % 10;
        a /= 10;
    }
    return ans == 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    int a;
    cin >> a;
    int b = 18;
    while (a > 0) {
        ++b;
        if (check(b)) --a;
    }
    cout << b << endl;
    return 0;
}