#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {  
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    for (int i=0; i < s.size(); i++){
        int len = s.size() - i;
        ans += max(0LL, len-12);
        bool can = false;
        for (int j=i; j < s.size(); j++){
            if (j-i >= 12) break;
            if (can){
                ans++;
                continue;
            }
            for (int k=1; j-2*k >= i; k++){
                if (s[j] == s[j-k] && s[j] == s[j-2*k]) can = true;
            }
            ans += can;
        }
    }
    cout << ans;
}