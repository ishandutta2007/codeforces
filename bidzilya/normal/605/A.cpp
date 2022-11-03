#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        b[a[i]] = i;
    }

    vector<int> c(n);
    c[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        c[i] = i;
        if (b[i + 1] > b[i]) {
            c[i] = c[i + 1];
        }
    }

    int ans = n;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, i + (n - c[i] - 1));
    }
    cout << ans << endl;

    return 0;
}