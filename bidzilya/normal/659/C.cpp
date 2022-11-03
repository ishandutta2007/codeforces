#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void UpdateResult(int l, int r, vector<int>& result, int& m) {
    while (l <= r && l <= m) {
        m -= l;
        result.push_back(l);
        ++l;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> result;

    UpdateResult(1, a[0] - 1, result, m);
    for (int i = 1; i < (int) a.size(); ++i) {
        UpdateResult(a[i - 1] + 1, a[i] - 1, result, m);
    }
    UpdateResult(a.back() + 1, 1e9, result, m);

    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}