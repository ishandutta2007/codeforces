#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    auto dist = [&](int a, int b)->int{
        return abs(a-b)+abs(arr[a]-arr[b]);
    };
    int ans = 0;
    for(int i = 0; i<n; i++){
        int end = n;
        for(int j = i+1; j<n; j++){
            for(int a = i; a<j; a++){
                for(int b = a+1; b<j; b++){
                    if(dist(a, b)+dist(b, j)==dist(a, j))
                        end = j;
                }
            }
            if(end != n) break;
        }
        ans += end-i;
    }
    cout << ans << '\n';
}

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}