#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int n;
char arr[MAXN];

void solve() {
    cin >> n;
    forn(i, 0, n) cin >> arr[i];
    // Find number of zeros
    int z = 0;
    forn(i, 0, n) {
        if(arr[i]=='1') break;
        z++;
    }
    int o = 0;
    for(int i = n-1; i>=0; i--) {
        if(arr[i]=='0') break;
        o++;
    }
    if(z==0 && o==0) {
        cout << 0 << endl;
        return;
    }
    forn(i, 0, z) cout << 0;
    // cout << 0;
    if(z+o!=n) cout << 0;
    forn(i, 0, o) cout << 1;
    
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t; while(t--)
    {solve();}
    return 0;
}