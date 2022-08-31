#include <bits/stdc++.h>
#define int long long
using namespace std;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for (int i=0; i < k; i++) cin >> v[i];
    vector<int> was(n);
    fill(was.begin(), was.end(), 0);
    vector<bool> checked(n);
    fill(checked.begin(), checked.end(), false);
    for (int i=0; i < k; i++){
        was[v[i]-1]++;
    }
    int ans=3*n-2;
    for (int i=0; i < k; i++){
        if (!checked[v[i]-1]){
            if (was[v[i]-1]) ans--;
            if (v[i] < n && was[v[i]]) ans--;
            if (v[i]-2 >= 0 && was[v[i]-2]) ans--;
        }
        checked[v[i]-1] = true;
        was[v[i]-1]--;
    }
    cout << ans;


}