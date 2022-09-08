#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 5555, inf = 111111111;

long long n, k, l, ans;

void gener(int poz, long long x) {
    if (x > n) {
        return;
    }
    ans++;
    gener(poz + 1, x * 10);
    gener(poz + 1, x * 10 + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    k = n;
    while (k != 0) {
        l++;
        k /= 10;
    }
    gener(1, 1);

    cout << ans;
    return 0;
}