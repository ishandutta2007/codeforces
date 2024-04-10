#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }

    const int kMaxA = 5000;
    vector<int> amount(kMaxA, 0);
    for (int i = 0; i < 2 * n; ++i) {
        ++amount[a[i]];
    }
    for (int i = 0; i < kMaxA; ++i) {
        if (amount[i] % 2 != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<int> last(kMaxA, -1);
    for (int i = 0; i < 2 * n; ++i) {
        if (last[a[i]] == -1) {
            last[a[i]] = i;
        } else {
            printf("%d %d\n", last[a[i]] + 1, i + 1);
            last[a[i]] = -1;
        }
    }

    return 0;
}