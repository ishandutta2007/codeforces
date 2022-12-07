// https://codeforces.com/contest/1493/problem/0

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    int n, k;
    cin >> n >> k;
    int arr[n];
    forn(i, n+1) arr[i] = 0;
    int ans = 0;
    for(int i = ((k/2)+1); i<=n; i++) {
        ans += 1;
        arr[i] = 1;
    }
    arr[k] = 0;
    ans -= 1;
    if(k%2==0) {
        arr[k/2] = 1;
        ans += 1;
    }
    cout << ans << endl;
    forn(i, n+1) {
        if(arr[i]==1) {
            cout << i << " ";
        }
    }
    cout << endl;
}
    return 0;
}