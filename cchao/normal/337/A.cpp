#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans = -1, a[100];

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) cin >> a[i];
    sort(a, a + m);
    for(int i = 0; i + n - 1 < m; ++i) {
        int t = a[i + n - 1] - a[i];
        if(ans == -1) ans = t;
        else ans = min(ans, t);
    }
    cout << ans << endl;
    return 0;
}