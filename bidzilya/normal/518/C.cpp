#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
        a[b[i]] = i;
    }

    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;

        ans += (a[x] / k);
        ++ans;

        if (a[x] > 0) {
            int prev_pos = a[x] - 1;
            int cur_pos = a[x];
            int y = b[prev_pos];

            b[prev_pos] = x;
            b[cur_pos] = y;

            a[x] = prev_pos;
            a[y] = cur_pos;
        }
    }

    cout << ans << endl;

    return 0;
}