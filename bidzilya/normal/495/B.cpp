#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "infinity" << endl;
    } else {
        int ans = 0;
        int c = abs(a - b);
        for (int i = 1; i * i <= c; ++i) {
            if (c % i == 0) {
                if (i > b) {
                    ++ans;
                }
                if (i * i != c) {
                    if (c / i > b) {
                        ++ans;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}