#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n, t;
    cin >> n;
    int arr[n];
    int o = 0, e = 0;
    forn(i, 0, n) {
        cin >> t;
        if(t%2) {
            arr[i] = 1;
            o++;
        }
        else {
            arr[i] = 0;
            e++;
        }
    }
    if(abs(o-e) > 1) {
        cout << -1 << endl;
        return;
    }
    vector <int> odd;
    vector <int> even;
    forn(i, 0, n) {
        if(arr[i]==1) odd.push_back(i);
        else even.push_back(i);
    }
    int ans = 1E18;
    if(n%2==0) {
        int temp = 0;
        int i = 0;
        for(auto j : odd) {
            temp += abs(j - i);
            i += 2;
        }
        ans = min(ans, temp);
        temp = 0;
        i = 0;
        for(auto j : even) {
            temp += abs(j - i);
            i += 2;
        }
        ans = min(ans, temp);
    }
    else {
        if(o > e) {
            int temp = 0;
            int i = 0;
            for(auto j : odd) {
                temp += abs(j - i);
                i += 2;
            }
            ans = min(ans, temp);
        }
        else {
            int temp = 0;
            int i = 0;
            for(auto j : even) {
                temp += abs(j - i);
                i += 2;
            }
            ans = min(ans, temp);
        }
    }
    cout << ans << endl;

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