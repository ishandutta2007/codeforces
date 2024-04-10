#include <algorithm>
#include <iostream>
#include <utility>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int diff = a[1] - a[0];
    for (int i = 2; i < n; ++i) {
        diff = max(diff, a[i] - a[i - 1]);
    }

    int ans = 1e9;
    for (int i = 1; i + 1 < n; ++i) {
        if (a[i + 1] - a[i - 1] <= diff) {
            cout << diff << endl;
            return 0;
        } else {
            ans = min(ans, a[i + 1] - a[i - 1]);
        }
    }

    cout << ans << endl;

    return 0;
}