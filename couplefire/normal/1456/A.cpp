#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, p, k; cin >> n >> p >> k;
        string s; cin >> s; s = "$"+s;
        int x, y; cin >> x >> y;
        int bad[k];
        fill(bad, bad+k, 0);
        for(int i = p; i<=n; i++){
            bad[i%k] += (s[i] == '0');
        }
        int ans = 1000000009;
        for(int i = 1; i<=n; i++){
            if(n-i+1 < p) break;
            ans = min(ans, bad[(p+i-1)%k]*x+(i-1)*y);
            if(s[p+i-1] == '0') bad[(p+i-1)%k]--;
        }
        cout << ans << endl;
    }
}