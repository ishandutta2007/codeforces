//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100100

long long n;
long long c[MAXN], even[MAXN], odd[MAXN], sum[MAXN];

// USE LONG LONG FOR SUMS ETC

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    long long t;
    cin >> t;
while(t--) {
    cin >> n;
    forn(i, n) cin >> c[i];
    sum[0] = c[0];
    sum[1] = c[1];
    for(long long i=2; i<n; i++) {
        sum[i] = sum[i-2] + c[i];
    }
    long long mins = c[0];
    for(long long i=0; i<n; i+=2) {
        if(c[i]<mins) mins = c[i];
        even[i/2] = sum[i] - mins + mins*(n-(i/2));
    }
    mins = c[1];
    for(long long i=1; i<n; i+=2) {
        if(c[i]<mins) mins = c[i];
        odd[(i-1)/2] = sum[i] - mins + mins*(n-((i-1)/2));
    }
    long long ans = 1E17;
    forn(i, n/2) {
        ans = min(ans, even[i]+odd[i]);
        if(i!=((n/2)-1)) {
            // ans = min(ans, even[i]+odd[i+1]);
            ans = min(ans, even[i+1]+odd[i]);
        }
    }
    if(n%2==1) {
        ans = min(ans, even[n/2]+odd[(n/2)-1]);
    }
    cout << ans << endl;
}
    return 0;
}