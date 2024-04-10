#include <bits/stdc++.h>

using namespace std;

int n, a[10];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    cout << a[n / 2] << '\n';
    return 0;
}