#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> l, r;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> x;
    l.resize(n);
    r.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += r[i] - l[i] + 1;
    }

    int cur = 1;
    int id = 0;
    while (id < n) {
        if (cur == l[id]) {
            cur = r[id] + 1;
            ++id;
        } else if (cur + x <= l[id]) {
            cur += x;
        } else {
            ++cur;
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}