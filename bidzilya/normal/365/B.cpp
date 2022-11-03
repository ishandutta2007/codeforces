#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 1e5 + 100;

int n;
int a[max_n];
int d[max_n];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    d[0] = 1;
    d[1] = 2;
    for (int i = 2; i < n; ++i)
        if (a[i] == a[i - 1] + a[i - 2]) {
            d[i] = d[i - 1] + 1;
        } else {
            d[i] = 2;
        }
    int mx = 0;
    for (int i = 0; i < n; ++i)
        mx = max(mx, d[i]);
    cout << mx << endl;
    return 0;
}