#include <algorithm>
#include <iostream>
#include <utility>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);

    long long t, a, b;

    cin >> t >> a >> b;

    if (a == 1) {
        if (t == 1) {
            if (b == 1) {
                cout << "inf" << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            if (b == 1) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
        return 0;
    }

    vector<long long> d;
    long long tb = b;
    while (tb > 0) {
        d.push_back(tb % a);
        tb /= a;
    }

    int cnt = 0;
    for (int i = 0; i < (int) d.size(); ++i) {
        if (d[i] != 0) {
            ++cnt;
        }
    }

    int ans = 0;
    if ((t != 1 && d.size() > 1) || (t == 1 && cnt != 1)) {
        tb = a;
        bool good = true;
        for (int i = 0; i < (int) d.size(); ++i) {
            if (tb < d[i]) {
                good = false;
                break;
            }
            tb -= d[i];
            if (tb % t != 0) {
                good = false;
                break;
            }
            tb /= t;
        }
        if (tb != 0) {
            good = false;
        }
        if (good) {
            ++ans;
        }
    }

    tb = b;
    while (tb % a == 0) {
        tb /= a;
    }
    if (b != 1 && tb == 1) {
        ++ans;
    }

    cout << ans << endl;

    return 0;
}