#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> h;
    for (int i=0; i < n; i++){
        int a, b;
        cin >> a >> b;
        h[a] = 0;
        h[a] = max(h[a], b);
    }
    int m;
    cin >> m;
    for (int i=0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if (!h.count(a)) h[a] = 0;
        h[a] = max(h[a], b);
    }
    int ans = 0;
    for (map<int, int>::iterator it = h.begin(); it != h.end(); it++){
        ans += (*it).second;
    }
    cout << ans;
}