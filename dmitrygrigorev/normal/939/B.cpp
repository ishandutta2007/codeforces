#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    int tp=0, num = 0;
    int n, k;
    cin >> n>> k;
    vector<int> v(k);
    for (int i=0; i < k; i++) cin >> v[i];
    for (int i=0; i < k; i++){
        int A = (n / v[i]) * v[i];
        if (A > ans){
            tp = i;
            ans = A;
            num = n/v[i];
        }
    }
    cout << tp+1 << " " << num << endl;
}