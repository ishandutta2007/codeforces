#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int poz = 0;
    while (poz + 1 < n && a[poz] == a[poz + 1]) {
        ++poz;
    }
    if (poz + 1 == n) {
        cout << "NO";
    } else {
        cout << a[poz + 1];
    }
    return 0;
}