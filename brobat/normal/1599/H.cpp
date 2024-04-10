#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
// const int INF = 9100000000000000000;
const double EPS = 1E-7;

int query(int x) {
    cout << "? 1 " << x << endl;
    int y; 
    cin >> y;
    return y;
}

void solve() {
    int E = MOD - 7;
    map<int, int> f; // f[i] = k means at co-ordinate (i, 1) the answer came j.
    int left = 1;
    int right = E;
    int x, y, p, q;
    f[left] = query(left);
    f[right] = query(right);
    while(left <= right) {
        int mid = (left + right)/2;
        f[mid] = query(mid);
        if(right - left == 1) {
            y = mid;
            x = f[mid] + 1;
            q = mid + 1;
            break;
        }
        bool upper = f[left] - f[mid] == mid - left;
        bool lower = f[right] - f[mid] == right - mid;
        if(upper && lower) {
            y = mid;
            x = f[mid] + 1;
            q = mid;
            break;
        }
        else if(!upper && !lower) {
            y = left + f[left] - f[mid];
            x = f[mid] + 1;
            q = right - (f[right] - f[mid]);
            break;
        }
        else if(!upper && lower) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    cout << "? " << E << " " << E << endl;
    int t;
    cin >> t;
    p = 2*E - q - t;
    cout << "! " << x << " " << y << " " << p << " " << q << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}