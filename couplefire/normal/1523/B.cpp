#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    vector<int> tmp = {2, 1, 1, 2, 1, 1};
    cout << 3*n << endl;
    for(int i = 0; i<n-1; i+=2)
        for(int j = 0; j<6; j++)
            cout << tmp[j] << " " << i+1 << " " << i+2 << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}