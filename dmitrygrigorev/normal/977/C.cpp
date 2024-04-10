#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    if (k==n) cout << v[n-1] << endl;
    else{
        if (k==0){
            if (v[0] == 1) cout << -1;
            else cout << v[0]-1;
        }
        else{
            if (v[k-1] == v[k]){
                cout << -1;
            }
            else cout << v[k-1];
        }
    }
    return 0;
}


/*

1
6 6
3 6
3 4
1 4
1 2
1 3
2 3

*/