#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for(int i = 0; i < m; i++) {
        string s;
        for(int j = 0; j < i; j++) s += '0';
        s += '1';
        for(int j = i + 1; j < m; j++) s += '0';
        cout << "? " << s << endl;
        int x;
        cin >> x;
        v[i] = {x, i};
    }
    sort(v.begin(), v.end());
    int ans = 0;
    vector <char> a(m, '0');
    for(int i = 0; i < m; i++) {
        a[v[i].second] = '1';
        cout << "? ";
        for(int i = 0; i < m; i++) cout << a[i];
        cout << endl;
        int x;
        cin >> x;
        if(x == ans + v[i].first) {
            ans += v[i].first;
        } else {
            a[v[i].second] = '0';
        }
    }
    cout << "! " << ans << endl;
    
    return 0;
}