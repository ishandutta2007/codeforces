// https://codeforces.com/contest/1501/problem/B

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200001
#define TWO 2

    int n;
    int arr[MAXN];
    array <int, 2> grr[MAXN];
    int ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n;
    forn(i, n) cin >> arr[i];
    forn(i, n) {
        grr[i][1] = i+1;
        grr[i][0] = max(i+1-arr[i],0);
    }
    sort(grr,grr+n);
    forn(i, n+1) ans[i] = 0;
    // forn(i, n) cout << "(" << grr[i][0] << "," << grr[i][1] << ") ";
    // cout << endl;
    // (0,2) (1,1) (3,3) (3,6) (4,4) (4,5)
    // (1,1) (1,6) (2,2) (3,3) (3,4) (5,5) (7,7) (8,8) (8,10) (9,9)
    // (1,1) (2,2) (3,3) 
    // (0,1) (1,2) (2,3) (3,4) (4,5)  (For 1,1,1,1,1)
    int processed = 0;
    forn(i, n) {
        if(grr[i][1]<=processed) {
            continue;
        }
        if(grr[i][1]==grr[i][0]) continue;
        // processed = grr[i][0];
        for(processed; processed<=grr[i][1]; processed++) {
            if(processed>grr[i][0]) ans[processed] = 1;
        }
        --processed;
    }
    forn(i, n) {
        cout << ans[i+1] << " ";
    }
    cout << endl;
}
    return 0;
}