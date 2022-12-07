#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> c >> d;
        if ((c & 1) != (d & 1)) {
            cout << -1 << "\n";
            continue;
        }
        if (c == 0 && d == 0)
            cout << "0\n";
        else if (c == d)
            cout << "1\n";
        else
            cout << "2\n";
    }
    return 0;
}