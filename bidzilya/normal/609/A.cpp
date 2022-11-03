#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int result = 0;
    for (int i = 0; i < n && m > 0; ++i) {
        int d = min(m, a[i]);
        m -= d;
        ++result;
    }

    cout << result << endl;

    return 0;
}