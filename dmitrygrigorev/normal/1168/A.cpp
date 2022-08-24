#include<bits/stdc++.h>
using namespace std;
signed main() {  
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    int L = -1, R = m+1;
    while (R-L>1){
        int M = (R+L)/2;
        int cur = 0;
        for (int i=0; i < n; i++){
            //if (M==0) cout << cur << endl;
            while (cur < m){
                if (v[i] <= cur){
                    int delta = cur - v[i];
                    if (delta <= M) break;
                    else cur++;
                }
                else{
                    int delta = cur-v[i] + m;
                    if (delta <= M) break;
                    else cur++;
                }
            }
        }
        if (cur == m) L = M;
        else R = M;
    }
    cout << R << endl;
}