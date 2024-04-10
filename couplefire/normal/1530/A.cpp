#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int ans = 0;
        for(char c : s)
            ans = max(ans, c-'0');
        cout << ans << '\n';
    }
}