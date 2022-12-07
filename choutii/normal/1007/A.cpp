#include <bits/stdc++.h>
using namespace std;

int n; map<int, int>c;

int main() {
    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        mx = max(mx, ++c[x]);
    }
    cout << n - mx << "\n";
}