#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    a = 'x' + a + 'x';
    b = 'x' + b + 'x';
    int ans = 0;
    int c1{0}, c2{0}, c3{0};
    bool taken[n+2];
    forn(i, 0, n+2) taken[i] = false;
    forn(i, 1, n+1) {
        if(a[i]=='0' && b[i]=='1') c3 += 1;
        if(a[i]=='1' && b[i]=='0') c3 += 1;  
        if(a[i]=='0' && b[i]=='0') c1 += 1;
        if(a[i]=='1' && b[i]=='1') {
            if(a[i-1]=='0'&&b[i-1]=='0') {
                if(!taken[i-1]) {
                    c2 += 1;
                    taken[i-1] = true;
                    continue;
                }
            }
            if(a[i+1]=='0'&&b[i+1]=='0') {
                c2 += 1;
                taken[i+1] = true;
            }
        }
    }
    ans = 2*(c3 + c2) + c1 - c2;
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}