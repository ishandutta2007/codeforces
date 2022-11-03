#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, d;
    cin >> n >> d;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    long long cur = 0;
    for (int l = 0, r = -1; l < n; ++l) {
        if (r < l) {
            r = l;
            cur = a[l].second;
        }
        while (r + 1 < n && a[r + 1].first < a[l].first + d) {
            ++r;
            cur += a[r].second;
        }
        ans = max(ans, cur);
        cur -= a[l].second;
    }
    cout << ans << endl;

    return 0;
}