#include <bits/stdc++.h>
using namespace std;

int a[55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x = *min_element(a + 1, a + n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++) if (a[i] == x) m++;
    if (m <= n / 2) return puts("Alice"), 0;
    return puts("Bob"), 0;
}