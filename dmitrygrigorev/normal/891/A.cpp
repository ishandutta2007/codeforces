#include <bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    int n, INF = 1e5;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    int diff = INF;
    int C = 0;
    for (int i=0; i < n; i++){
        if (v[i] == 1) C++;
    }
    if (C > 0){
        cout << n - C << endl;
        return 0;
    }
    for (int i=0; i < n; i++){
        int g = v[i];
        for (int j=i+1; j < n; j++){
            g = gcd(g, v[j]);
            if (g == 1) diff = min(diff, j-i);
        }
    }
    if (diff == INF) cout << -1 << endl;
    else cout << n - 1 + diff << endl;
    return 0;
}