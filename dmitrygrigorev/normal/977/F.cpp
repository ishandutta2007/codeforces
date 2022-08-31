#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    map<int, int> ind, ans;
    int a = 0, best=-1;
    vector<int> wh(n);
    for (int i=n-1; i >= 0; i--){
        if (ans.count(v[i] + 1)){
            ans[v[i]] = ans[v[i]+1]+1;
            wh[i] = ind[v[i]+1];
            ind[v[i]] = i;
            if (a < ans[v[i]]){
                a = ans[v[i]];
                best = i;
            }
        }
        else{
            ans[v[i]] = 1;
            ind[v[i]] = i;
            wh[i] = -1;
            if (a < ans[v[i]]){
                a = ans[v[i]];
                best = i;
            }
        }
    }
    int nd = best;
    cout << a << endl;
    while (best != -1){
        cout << best+1 << " ";
        best = wh[best];
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