#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

bool check(int a, int b, int c) {
    if((c>=b&&b>=a)||(c<=b&&b<=a)) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    int n;
    cin >> n;
    int arr[n];
    forn(i, n) cin >> arr[i];
    ll ans = 0;
    forn(i, n) {
        // cout << ans << " ";
        int k = n - i;
        if(k==1) ans += 1;
        else if(k==2) ans += 2;
        else if(k==3) {
            if(check(arr[i], arr[i+1], arr[i+2])) ans += 3;
            else ans += 2;
        }
        else {
            ans += 2;
            if(check(arr[i], arr[i+1], arr[i+2])) {
                ans += 1;
                if(check(arr[i], arr[i+1], arr[i+3])&&check(arr[i], arr[i+2], arr[i+3])&&check(arr[i+1], arr[i+2], arr[i+3])) ans+=1;
            }
        }
    }
    cout << ans << endl;
}
    return 0;
}