#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s, t; cin >> s >> t;
        int ans = 0;
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1' && t[i] == '1') {flag = true; continue; }
            if(s[i] != t[i]) ans += 2;
            if(s[i] == '0' && t[i] == '0')
            {
                if(i > 0 && flag) ans += 2;
                else if(i < n-1 && s[i+1] == '1' && t[i+1] == '1') { ans += 2; i++; }
                else ans += 1;
            }
            flag = false;
        }
        cout << ans << "\n";
    }
}