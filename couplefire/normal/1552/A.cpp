#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        string tmp = s;
        sort(s.begin(), s.end());
        int ans = 0;
        for(int i = 0; i<n; i++)
            ans += (s[i]!=tmp[i]);
        cout << ans << '\n';
    }
}