//

#include <bits/stdc++.h>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    long long t;
    cin >> t;
while(t--) {
    long long n;
    cin >> n;
    long long arr[n];
    forn(i, n) cin >> arr[i];
    sort(arr, arr+n);
    long long grr[n-1];
    forn(i, n-1) grr[i] = arr[i+1]-arr[i];
    long long brr[n-1];
    brr[0] = grr[0];
    forn(i, n-1) brr[i+1] = brr[i] + (grr[i+1]*(i+2));
    // forn(i, n-1) cout << brr[i] << " ";
    long long ans = 0;
    forn(i, n-1) {
        ans += grr[i];
        ans -= brr[i];
    }
    cout << ans << endl;
} 
    return 0;
}