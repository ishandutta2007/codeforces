#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int id[N];
long long a[N];

int main() {
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], id[i] = i;
    sort(id + 1, id + n + 1, [](int i, int j) {
         return a[i] > a[j];
    });
    long long ans = 0;
    vector<int> v;
    for (int i = 1; i <= m * k; i++) {
        ans += a[id[i]];
        v.push_back(id[i]);
    }
    sort(v.begin(), v.end());
    cout << ans << endl;
    for (int i = 0; i < k-1; i++) {
        cout << v[i*m+m-1] << ' ';
    }
    cout << endl;
    return 0;
}