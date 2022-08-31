#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    vector<int> ans = {0};
    int sum = v[0], kek=0;
    for (int i=1; i < n; i++){
        if (2*v[i] > v[0]){
            kek += v[i];
            continue;
        }
        ans.push_back(i);
        sum += v[i];
    }
    if (kek >= sum){
        cout << 0;
    }
    else{
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++) cout << ans[i]+1 << " ";
    }
}