#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    int arr[n];
    forn(i, 0, n) {
        cin >> arr[i];
        if(i%2==1) arr[i] *= -1;
    }
    int ans = 0;
    for(int i = 0; i < n; i += 2) {
        int start = arr[i];
        int temp = 0;
        forn(j, i + 1, n) {
            if(arr[j] > 0) temp += arr[j];
            else {
                int x = arr[j] * -1ll;
                if(x < temp) {
                    temp -= x;
                    continue;
                }
                if(x == temp) {
                    ans++;
                    temp = 0;
                    continue;
                }
                x -= temp;
                if(temp > 0) ans++; 
                temp = 0;
                if(x > start) {
                    ans += start;
                    break;
                }
                else {
                    ans += x;
                    start -= x;
                }
            }
        }
        // cout << ans << endl;
    }
    cout << ans;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}