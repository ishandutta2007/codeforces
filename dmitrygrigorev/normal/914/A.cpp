#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    set<int> ms;
    for (int i=0; i <= 2000; i++){
        ms.insert(i*i);
    }
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i=n-1; i >= 0; i--){
        if (ms.count(v[i])) continue;
        cout << v[i] << endl;
        return 0;
    }
    return 0;
}