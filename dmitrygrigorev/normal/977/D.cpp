#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    vector<vector<int> > trip(100);
    for (int i=0; i < n; i++){
        int p = v[i], tr=0;
        while (p%3==0){
            p /= 3;
            tr++;
        }
        trip[tr].push_back(v[i]);
    }
    for (int i=99; i >= 0; i--){
        sort(trip[i].begin(), trip[i].end());
        for (int j=0; j < trip[i].size(); ++j) cout << trip[i][j] << " ";
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