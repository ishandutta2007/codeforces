#include <bits/stdc++.h>
using namespace std;

const int N = 10123;
int a[N];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n - 1; i++) {
        ans += ((a[i] < a[i - 1] && a[i] < a[i + 1]) || (a[i] > a[i - 1] && a[i] > a[i + 1]));
    }
    cout << ans;
}
// coding in mobile :/