#include <bits/stdc++.h>
#define int long long
using namespace std ;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0) ;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i=0; i < n; i++) sum += v[i];
    if (sum % 2 == 0){
        for (int i=n-1; i >= 0; i--){
            if (v[i] == 1){
                if (i==n-1) break;
                swap(v[i], v[n-1]);
                break;
            }
        }
    }
    if (v[0] == 1 && v[1] == 2) swap(v[0], v[1]);
    for (int i=0; i < n; i++) cout << v[i] << " ";
    return 0;
}