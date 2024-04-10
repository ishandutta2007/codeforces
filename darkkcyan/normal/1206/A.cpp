#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 111;
int n, m;
int a[maxn];
int b[maxn];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    cout << a[n - 1] << ' ' << b[m - 1];

}