#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n; cin >> n;
    int left = 1;
    int right = n;
    int add = 0;
    int temp;
    int curr_highest = 0;
    while(left < right) {
        int mid = (left + right + 1)/2;
        // cout << "+ " << mid << endl;
        // cout << "+ " << left << " " << right << " " << mid << endl;
        // ASSUME that x is mid. Try to find if x is in [left, mid - 1] or [mid, right].
        cout << "+ " << (curr_highest+1)*n - mid - add << endl;
        add += (curr_highest+1)*n - mid - add;
        cin >> temp;
        if(temp > curr_highest) {
            curr_highest = temp;
            left = mid;
        }
        else {
            right = mid - 1;
        }
    }
    cout << "! " << left + add << endl;
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