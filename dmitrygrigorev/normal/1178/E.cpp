#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    string ans;
    for (int i=0; i < s.size() / 4; i++){
        char A = s[2*i], B = s[2*i+1], C = s[s.size()-1-2*i], D = s[s.size()-2-2*i];
        if (A==C || A==D) ans += A;
        else ans += B;
    }
    cout << ans;
    if (s.size() % 4 != 0){
        int T = 2*(s.size()/4);
        cout << s[T];
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}