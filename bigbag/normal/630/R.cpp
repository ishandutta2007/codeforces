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

const int max_n = 555;

long long n, ans, f[6];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    ans = ((n % 2) ^ 1) + 1;
    cout << ans << endl;
    return 0;
}