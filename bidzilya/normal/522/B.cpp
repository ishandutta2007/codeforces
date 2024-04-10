#include <bits/stdc++.h>
using namespace std;

int main()
{
  //  freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> w(n), h(n);
    int w_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> h[i];
        w_sum += w[i];
    }
    vector<int> sh(h.begin(), h.end());
    sort(sh.begin(), sh.end());
    for (int i = 0; i < n; ++i) {
        if (h[i] == sh[n - 1]) {
            cout << (w_sum - w[i]) * sh[n - 2] << " ";
        } else {
            cout << (w_sum - w[i]) * sh[n - 1] << " ";
        }
    }
    cout << endl;

    return 0;
}