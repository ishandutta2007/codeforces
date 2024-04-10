#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = 100 + 7;
int n, a[N], d[N];

void rec(int l, int r) {
        if (l > r)
                return;
        int j = l;
        for (int i = l + 1; i <= r; i++)
                if (a[i] > a[j])
                        j = i;
        for (int j = l; j <= r; j++)
                d[j]++;
        rec(l, j - 1);
        rec(j + 1, r);

}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        int t;
        cin >> t;
        while (t--) {
                cin >> n;
                for (int i = 1; i <= n; i++)
                        cin >> a[i];
                rec(1, n);
                for (int i = 1; i <= n; i++) {
                        cout << d[i] - 1 << " ";
                        d[i] = 0;
                }
                cout << "\n";
        }

}