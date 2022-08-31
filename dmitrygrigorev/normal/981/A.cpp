#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    for (int i=0; i < s.size(); i++){
        for (int j=i; j < s.size(); j++){
            string a = "", b = "";
            for (int p=i; p <= j; p++) a += s[p];
            for (int p=j; p >= i; p--) b += s[p];
            if (a==b) continue;
            ans = max(ans, j-i+1);
        }
    }
    cout << ans;
}