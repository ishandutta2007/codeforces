#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        while (n) {
            if (n & 1) {
                assert(n >= 3);
                int a, b, c;
                cin >> a >> b >> c;
                if (a + b != 0)
                    cout << c << " " << c << " " << -(a + b) << " ";
                else if (a + c != 0)
                    cout << b << " " << -(a + c) << " " << b << " ";
                else if (b + c != 0)
                    cout << -(b + c) << " " << a << " " << a << " ";
                else
                    assert(0);
                n -= 3;
            }
            else {
                int a, b;
                cin >> a >> b;
                cout << b << " " << -a << " ";
                n -= 2;
            }
        }
        cout << endl;
    }
}