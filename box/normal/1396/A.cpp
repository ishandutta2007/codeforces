// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
#define int ll
const int MOD = 1000000007;

int ar[100005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    if(n == 1) {
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cin >> n;
        cout << -n << endl;
    } else {
        cout << 1 << ' ' << n-1 << endl;
        rep1(i, n) {
            cin >> ar[i];
            if(i != n) {
                ll dt = (n-1) * ((ar[i] + n * 10000000000ll) % n);
                cout << dt << ' ';
                ar[i] += dt;
            } else {
                cout << endl << n << ' ' << n << endl << -ar[n] << endl;
                ar[n] = 0;
            }
        }
        cout << 1 << ' ' << n << endl;
        rep1(i, n) {
            assert((n * 10000000000ll + ar[i]) % n == 0);
            cout << -ar[i] << ' ';
        }
    }
}