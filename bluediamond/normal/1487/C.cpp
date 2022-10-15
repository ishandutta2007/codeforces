#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

         /// 0 1 1
        //    1 1
        //      0

        int t;
        cin >> t;
        while (t--) {
                int n;
                cin >> n;
                if (n % 2 == 0) {
                        for (int i = 1; i <= n; i++)
                                for (int j = i + 1; j <= n; j++)
                                        if (j == i + 1 && i % 2 == 1)
                                                cout << "0 ";
                                        else
                                                if ((j - i) % 2)
                                                        cout << "1 ";
                                                else
                                                        cout << "-1 ";
                        cout << "\n";
                } else {
                        for (int i = 1; i <= n; i++)
                                for (int j = i + 1; j <= n; j++)
                                        if ((j - i) % 2)
                                                cout << "1 ";
                                        else
                                                cout << "-1 ";
                        cout << "\n";
                }
        }
}