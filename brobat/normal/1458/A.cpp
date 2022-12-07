#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // long long t; cin >> t; while(t--)
{
    // Code goes here
    long long n, m;
    cin >> n >> m;
    long long arr[n];
    long long brr[m];
    forn(i, n) cin >> arr[i];
    forn(i, m) cin >> brr[i];
    sort(arr, arr+n);
    if(n==1) {
        forn(i, m) cout << arr[0] + brr[i] << " ";
        return 0;
    }
    if(n==2) {
        forn(i, m) cout << __gcd(arr[0] + brr[i], arr[1] + brr[i]) << " ";
        return 0;
    }
    long long gcd = arr[1] - arr[0];
    forn(i, n-2) gcd = __gcd(gcd, arr[i+2] - arr[i+1]);
    forn(i, m) cout << __gcd(arr[0]+brr[i], gcd) << " ";
}
    return 0;
}