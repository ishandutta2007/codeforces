#include <iostream>

using namespace std;

int main()
{
    long long a, n, b, d, k = 0, ans = 0, i;
    cin >> n >> b >> d;
    for (i = 0; i<n; i++) {
        cin >> a;
        if (a <= b) {
            k += a;
        }
        if (k > d) {
            k = 0;
            ans++;
        }
    }
    cout << ans;
    return 0;
}