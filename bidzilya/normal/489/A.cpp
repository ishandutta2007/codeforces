#include <bits/stdc++.h>
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

    vector<pair<int, int> > ans;
    for (int i = 0; i < n; ++i) {
        int j = i;
        for (int k = i + 1; k < n; ++k) {
            if (a[k] < a[j]) {
                j = k;
            }
        }
        ans.push_back(make_pair(i, j));
        swap(a[i], a[j]);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}