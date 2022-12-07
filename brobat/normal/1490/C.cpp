//

#include <bits/stdc++.h>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
#define MAXN 10100
#define MOD 1000000007

long long cube[MAXN];
long long n;

// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
long long binarySearch(long long l, long long r, long long x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (cube[m] == x)
            return m;

        // If x greater, ignore left half
        if (cube[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    forn(i, MAXN) cube[i] = i*i*i;
    long long t;
    cin >> t;
while(t--) {
    bool a = false;
    cin >> n;
    for(long long i=1; i<MAXN; i++) {
        if(cube[i]>=n) break;
        long long result = binarySearch(0, MAXN, n-cube[i]);
        if(result!=-1) {
            a = true;
            break;
        }
    }
    if(a) cout << "YES" << endl;
    else cout << "NO" << endl;
}
    return 0;
}