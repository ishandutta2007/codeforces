#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr[5];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<5; j++){
            int x; cin >> x;
            arr[j].push_back(x);
        }
    }
    auto beat = [&](int x, int y)->bool{
        int cnt = 0;
        for(int i = 0; i<5; i++)
            cnt += arr[i][x]<arr[i][y];
        return cnt>=3;
    };
    int cur = 0;
    for(int i = 1; i<n; i++)
        if(beat(i, cur)) cur = i;
    int cnt = 0;
    for(int i = 0; i<n; i++)
        if(i != cur) cnt += beat(cur, i);
    cout << (cnt==n-1?cur+1:-1) << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}