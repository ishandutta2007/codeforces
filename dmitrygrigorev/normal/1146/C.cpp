#include <bits/stdc++.h>
#define int long long
using namespace std;
main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int it=0; it < t; it++){
        int n;
        cin >> n;
        int ans = 0;
        for (int i=0; i < 9; i++){
            vector<int> a, b;
            for (int j=0; j < n; j++){
                int ba = j & (1<<i);
                if (ba==0) a.push_back(j);
                else b.push_back(j);
            }
            if (a.size() == 0 || b.size() == 0) continue;
            cout << a.size() << " " << b.size() << " ";
            for (int j=0; j < a.size(); j++) cout << a[j]+1 << " ";
            for (int j=0; j < b.size(); j++) {
                cout << b[j]+1;
                if (j + 1 < b.size()) cout << " ";
            }
            cout << endl;
            int res;
            cin >> res;
            ans = max(ans, res);
        }
        cout << -1 << " " << ans << endl;
    }
}