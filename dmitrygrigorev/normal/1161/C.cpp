#include <bits/stdc++.h>
#define int long long
using namespace std;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    int mn = 100, cnt = 0;
    for (int i=0;i<n;i++){
        if (v[i] < mn){
            mn = v[i], cnt=1;
        }
        else if (v[i] == mn) cnt++;
    }
    if (cnt > n/2) cout << "Bob";
    else cout << "Alice";
}