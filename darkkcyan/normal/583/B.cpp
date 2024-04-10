#include<iostream>
using namespace std;

int n;
int a[1010];

int main() {
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; ++i) cin >> a[i];
    int dir = 1;
    int ans = 0;
    int picked = 0;
    for (int i = 0; ; i += dir) {
        if (a[i] <= picked) {
            ++picked;
            a[i] = n + 1;
        }
        if (picked == n) break;
        if (i == 0 and dir == -1) {
            dir = 1;
            ++ans;
        }
        if (i == n - 1 and dir == 1) {
            dir = -1;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}