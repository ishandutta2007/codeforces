#include <bits/stdc++.h>
using namespace std;

const int kMaxA = 1e6;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(2 * kMaxA + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    vector<int> nl(2 * kMaxA + 1, -1);
    for (int i = 1; i <= 2 * kMaxA; ++i) {
        if (a[i]) {
            nl[i] = i;
        } else {
            nl[i] = nl[i - 1];
        }
    }

    int ans = 0;
    for (int i = 2; i <= kMaxA; ++i) {
        if (a[i]) {
            for (int j = 2 * i; j - i <= kMaxA; j += i) {
                int r = nl[j - 1];
                if (r != -1 && r >= j - i) {
                    ans = max(ans, r - (j - i));
                }
            }
        }
    }

    cout << ans << endl;


    return 0;
}