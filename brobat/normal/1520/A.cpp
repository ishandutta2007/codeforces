//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 55
#define MOD 1000000007

int n;
char arr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    map<char, int> m;
    int ans = 1;
    cin >> n;
    forn(i, n) cin >> arr[i];
    m[arr[0]] += 1;
    forn(i, n-1) {
        if(arr[i+1]!=arr[i]) {
            m[arr[i+1]] += 1;
            if(m[arr[i+1]]==2) {
                ans = 0;
                break;
            }
        }
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}
    return 0;
}