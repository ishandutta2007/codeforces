#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int ans1 = -1, ans2 = -1;
string P;

int main() {
    int N, K;
    cin >> N >> K;
    cout << "1 1 2" << endl << flush;
    cin >> P;
    if (P == "TAK") {
        ans1 = 1;
    } else {
        int L = 1, R = N;
        while (L + 1 < R) {
            int mid = (L + R) / 2;
            cout << 1 << " " << mid << " " << mid + 1 << endl << flush;
            cin >> P;
            if (P == "TAK") R = mid; else L = mid;
        }
        ans1 = R;
    }
    if (ans1 >= 2) {
        int L = 1, R = ans1 - 1;
        while (L + 1 < R) {
            int mid = (L + R) / 2;
            cout << 1 << " " << mid << " " << mid + 1 << endl << flush;
            cin >> P;
            if (P == "TAK") R = mid; else L = mid;
        }
        cout << 1 << " " << R << " " << ans1 << endl << flush;
        cin >> P;
        if (P == "TAK") ans2 = R;
        cout << 1 << " " << L << " " << ans1 << endl << flush;
        cin >> P;
        if (P == "TAK") ans2 = L;
    }
    if (ans1 <= N - 1 && ans2 == -1) {
        int L = ans1 + 1, R = N;
        while (L + 1 < R) {
            int mid = (L + R) / 2;
            cout << 1 << " " << mid << " " << mid + 1 << endl << flush;
            cin >> P;
            if (P == "TAK") R = mid; else L = mid;
        }
        cout << 1 << " " << R << " " << ans1 << endl << flush;
        cin >> P;
        if (P == "TAK") ans2 = R;
        cout << 1 << " " << L << " " << ans1 << endl << flush;
        cin >> P;
        if (P == "TAK") ans2 = L;
    }

    cout << 2 << " " << ans1 << " " << ans2 << endl << flush; 
    return 0;
}