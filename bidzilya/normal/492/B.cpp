#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double ans = 0.0;
    ans = a[0];
    ans = max(ans, (double) l - a[n - 1]);
    for (int i = 1; i < n; ++i) {
        ans = max(ans, (a[i] - a[i - 1]) / 2.0);
    }

    cout << fixed << setprecision(15);
    cout << ans << endl;
    return 0;
}