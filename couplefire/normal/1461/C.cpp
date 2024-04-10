#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    int arr[n+1];
    for(int i = 0; i<n; i++) cin >> arr[i+1];
    int cmax = 0;
    int cmin = n+1;
    int ma[n+1], mi[n+2];
    ma[0] = 0;
    mi[n+1] = n+1;
    for(int i = 1; i<=n; i++){
        cmax = max(cmax, arr[i]);
        ma[i] = cmax;
    }
    for(int i = n; i>=1; i--){
        cmin = min(cmin, arr[i]);
        mi[i] = cmin;
    }
    int bad = 0;
    for(int i = 0; i<=n; i++){
        if(ma[i] > mi[i+1]) bad = i+1;
    }
    // cout << arr[2] << " " << mi[n+1] << endl;
    // cout << bad << endl;
    double ans = 1.0;
    for(int i = 0; i<m; i++){
        int r; cin >> r;
        double p; cin >> p;
        if(r >= bad) ans *= (1.0-p);
    }
    if(bad == 0){
        cout << 1 << endl;
        return;
    }
    cout << 1.0-ans << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << fixed;
    cout << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}