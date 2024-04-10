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
        string ss[n];
        for(int i = 0; i<n; i++) cin >> ss[i];
        int ans = 0;
        for(int i = 0; i<m-1; i++) ans += ss[n-1][i] == 'D';
        for(int i = 0; i<n-1; i++) ans += ss[i][m-1] == 'R';
        cout << ans << endl;
    }
}