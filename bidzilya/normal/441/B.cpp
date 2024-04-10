#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, v;
    cin >> n >> v;

    const int kMaxTime = 3e3 + 100;
    vector<int> a(kMaxTime);

    for (int i = 0; i < n; ++i) {
        int cur_time;
        int cur_value;
        cin >> cur_time >> cur_value;
        a[cur_time] += cur_value;
    }

    int ans = 0;
    for (int i = 0; i < kMaxTime; ++i) {
        int cv = v;
        if (i - 1 > 0) {
            int d = min(cv, a[i - 1]);
            a[i - 1] -= d;
            cv -= d;
        }
        int d = min(cv, a[i]);
        a[i] -= d;
        cv -= d;

        ans += (v - cv);
    }

    cout << ans << endl;

    return 0;
}