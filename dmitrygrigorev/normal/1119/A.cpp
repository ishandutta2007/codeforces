#include <bits/stdc++.h>
#define int long long
using namespace std;
main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++){
        cin >> v[i];
    }
    int nt = -1;
    for (int i=1; i < n; i++) if (v[i] != v[0]){
        nt = i;
        break;
    }
    int ans = 0;
    for (int i=0; i < n; i++){
        if (v[i] != v[0]){
            ans = max(ans, i);
        }
        else{
            ans = max(ans, abs(nt-i));
        }
    }
    cout << ans;

}