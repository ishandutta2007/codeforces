#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int n;
vector<int> v;

void solve() {
    cin >> n;
    v.clear();
    forn(i, 0, n) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    for(int i = 0; i <= MAXN; i++) {
        if(is_sorted(v.begin(), v.end())) {
            cout << i << endl;
            break;
        }
        if(i%2 == 0) {
            // Odd.
            for(int j = 0; j<n-2; j+=2) {
                if(v[j]>v[j+1]) swap(v[j], v[j+1]);
            }
        }
        else {
            // Even.
            for(int j = 1; j<n-1; j+=2) {
                if(v[j]>v[j+1]) swap(v[j], v[j+1]);
            }
        }
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