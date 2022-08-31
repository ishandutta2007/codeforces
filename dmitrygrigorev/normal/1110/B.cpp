#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    if (k >= n){
        cout << n;
        return 0;
    }
    vector<int> holes;
    sort(v.begin(), v.end());
    for (int i=0; i < n-1; i++) holes.push_back(v[i+1] - v[i]-1);
    sort(holes.begin(), holes.end(), greater<int>());
    int ans = v[n-1] - v[0] + 1;
    for (int i=0; i < k-1; i++){
        ans -= max((int) 0, holes[i]);
    }
    cout << ans;
}