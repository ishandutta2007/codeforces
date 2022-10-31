#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<int> k(n);
        vector<int> c(m);
        for(int i = 0; i<n; i++) cin >> k[i], --k[i];
        for(int i = 0; i<m; i++) cin >> c[i];
        long long tot = 0, ans = 1e17;
        sort(k.begin(), k.end()); reverse(k.begin(), k.end());
        for(int i = 0; i<n; i++) tot += c[k[i]];
        for(int i = 0; i<min(n, m); i++){
            if(k[i] < i) break;
            tot -= c[k[i]]; tot += c[i];
            ans = min(ans, tot);
        }
        cout << ans << endl;
    }
}