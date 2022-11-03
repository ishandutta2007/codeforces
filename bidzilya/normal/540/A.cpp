#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int i1 = s[i] - '0';
        int i2 = t[i] - '0';
        ans += min(abs(i1 - i2), min(10 - i1 + i2, i1 + 10 - i2));
    }
    cout << ans << endl;
    
    return 0;
}