#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n;

int a[200005], b[200005], c[200005];

int main() {
    // freopen("2.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <=n; ++i)
        cin >> b[i];
    for(int i = 1; i <= n; ++i)
        c[b[i]] = i;
    int mx = 0;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        a[i] = c[a[i]];
        mx = max(mx, a[i]);
        if(mx > a[i]) {
            cout << n - i+1 << "\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}