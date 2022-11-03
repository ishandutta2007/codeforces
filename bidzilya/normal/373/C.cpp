#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int max_n = 5e5 + 100;

int n;
int a[max_n];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int ans = n;
    int del = n / 2;
    for (int i1 = 0, i2 = del; i1 < del; ++i1) {
        while (i2 < n && a[i1] * 2 > a[i2]) ++i2;
        if (i2 < n) {
            ++i2;
            --ans;
        }
    }
    cout << ans << endl;
    return 0;
}