#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (int i=0; i < 5;i++){
        string t;
        cin >> t;
        if (s[0] == t[0] || s[1] == t[1]){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}