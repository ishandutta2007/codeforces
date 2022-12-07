//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
long long arr[MAXN];
    long long ans = 0;
    cin >> n;
    forn(i, n) {
        cin >> arr[i];
        arr[i] -= i;
    }
    map <long long, long long> m;
    forn(i, n) m[arr[i]] += 1;
    for(int i = (n*-1); i<=n; i++) {
        if(m[i]>1) {
            long long temp = m[i] * (m[i]-1);
            ans += temp/2;
        }
    }
    cout << ans << endl;
}
    return 0;
}