#include <iostream>

using namespace std;

const int maxn = 2000;

int a[maxn], b[maxn];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] > b[i]) swap(a[i], b[i]);
    }
    long long ans = 1e18;
    for (int i = 0; i < n; ++i) {
        long long H = a[i], W = b[i];
        bool fl = true;
        for (int j = 0; (j < n) && fl; ++j) {
            if (j == i) continue;
            if (b[j] <= H) {
                W += a[j];
            } else if (a[j] <= H) {
                W += b[j];
            } else {
                fl = false;
            }
        }
        if (fl) ans = min(ans, W * H);
        H = b[i], W = a[i];
        fl = true;
        for (int j = 0; (j < n) && fl; ++j) {
            if (j == i) continue;
            if (b[j] <= H) {
                W += a[j];
            } else if (a[j] <= H) {
                W += b[j];
            } else {
                fl = false;
            }
        }
        if (fl) ans = min(ans, W * H);
    }
    cout << ans << endl;

    return 0;
}