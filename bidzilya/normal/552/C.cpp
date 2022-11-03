#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long w, m;
    cin >> w >> m;

    if (w == 2) {
        cout << "YES" << endl;
        return 0;
    }

    while (true) {
        if (m % w == 0) {
            m /= w;
            continue;
        }
        if (m % w == w - 1) {
            ++m;
            continue;
        }
        if (m % w == 1) {
            --m;
            if (m == 0) {
                break;
            }
            continue;
        }
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    return 0;
}