#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    vector <int> v(n+1);
    char temp;
    v[0] = -1;
    int first_zero = -1;
    forn(i, 0, n) {
        cin >> temp;
        if(temp=='1') v[i+1] = 1;
        else {
            v[i+1] = 0;
            if(first_zero == -1) first_zero = i + 1;
        }
    }
    if(first_zero == -1) {
        if(n%2==0) {
            cout << 1 << " " << n << " " << 1 << " " << n/2 << endl;
        }
        else {
            cout << 1 << " " << n-1 << " " << 1 << " " << n/2 << endl;
        }
        return;
    }
    if(first_zero <= n/2) {
        cout << first_zero << " " << n << " " << first_zero + 1 << " " << n << endl;
    }
    else {
        cout << 1 << " " << first_zero << " " << 1 << " " << first_zero - 1 << endl;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}