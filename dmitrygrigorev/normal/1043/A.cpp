#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    int L = 0;
    for (int i=0;i<n;i++) L = max(L, v[i]);
    int R = 1e9;
    L--;
    while (R-L>1){
        int M = (L+R)/2;
        int v1 = 0, v2=0;
        for (int i=0;i<n;i++) v1 += v[i];
        for (int i=0;i<n;i++) v2 += M-v[i];
        if (v2 > v1) R = M;
        else L = M;
    }
    cout << R;

}