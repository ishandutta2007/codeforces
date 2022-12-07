// https://codeforces.com/problemset/problem/1227/B

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100000

int n;
int arr[MAXN];
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
    forn(i, n) ans[i] = 0;
    // ans[0] = arr[0]. if arr[1]>arr[0] --> ans[1] = arr[1]. if arr[1]==arr[0], leave arr[0] for now.
    ans[0] = arr[0];
    forn(i, n-1) if(arr[i+1]>arr[i]) ans[i+1] = arr[i+1];
    queue <int> q;
    int val[n];
    forn(i, n) val[i] = 1;
    forn(i, n) val[arr[i]-1] = 0;
    forn(i, n) if(val[i]==1) q.push(i+1);
    // forn(i, n) cout << val[i] << " ";
    // cout << endl;
    forn(i, n) {
        if(ans[i]==0) {
            ans[i] = q.front();
            q.pop();
        }
    }
    int z = 1;
    forn(i, n) {
        if(ans[i]>arr[i]) z = 0;
    }
    if(z==0) cout << -1 << endl;
    else {
        forn(i, n) cout << ans[i] << " ";
        cout << endl;
    }

}
    return 0;
}