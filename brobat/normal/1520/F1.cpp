//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

int n, t, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n >> t >> k;
    int l = 1, r = n;
    while(l < r) {
        int mid = (l+r)/2;
        cout << "? " << l << " " << mid << endl;
        int dummy;
        cin >> dummy;
        int nz = mid+1-dummy-l;
        if(nz < k) {
            k -= nz;
            l = mid+1;
        }
        else {
            r = mid;
        }
    }
    cout << "! " << l;
    return 0;
}