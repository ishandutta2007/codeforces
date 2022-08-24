#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    int ans = 0;
    string s;
    cin >> s;
    for (int i=0; i < s.size(); i++){
        for (int j=i+1; j < s.size(); j++){
            for (int k=j+1; k < s.size(); k++){
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}