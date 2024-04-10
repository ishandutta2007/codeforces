#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int ans = 0;
    string p = "13579aeiuo";
    for (int i=0; i < s.size(); i++){
        for (int j=0; j < 10; j++){
            if (s[i] == p[j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}