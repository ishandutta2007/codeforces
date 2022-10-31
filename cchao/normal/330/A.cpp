#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    bool r[10]={}, c[10]={};
    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < m; ++j)
            if(s[j] == 'S') r[i] = c[j] = true;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(!r[i] || !c[j]) ans++;
    cout << ans << endl;
    return 0;
}