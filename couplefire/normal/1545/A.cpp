#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    map<int, int> pos[2];
    map<int, int> npos[2];
    for(int i = 0; i<n; i++)
        pos[i%2][arr[i]]++;
    sort(arr.begin(), arr.end());
    for(int i = 0; i<n; i++)
        npos[i%2][arr[i]]++;
    for(int i = 0; i<n; i++)
        if(pos[0][arr[i]] != npos[0][arr[i]] || pos[1][arr[i]] != npos[1][arr[i]]){
            cout << "NO" << endl;
            return;
        }
    cout << "YES" << endl;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}