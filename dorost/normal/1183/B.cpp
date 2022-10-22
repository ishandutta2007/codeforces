#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

signed main(){
    int q;
    cin >> q;
    while (q--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort (a, a + n);
        if (a[n - 1] - a[0] > k + k){
            cout << -1 << endl;
        }else{
            cout << a[0] + k << endl;
        }
    }
}