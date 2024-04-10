#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m, x; cin >> n >> m >> x;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
        vector<int> ans(n);
        for(int i = 0; i<m; i++) pq.push({0, i});
        for(int i = 0; i<n; i++){
            int h; cin >> h;
            auto x = pq.top(); pq.pop();
            x[0] += h;
            ans[i] = x[1];
            pq.push(x);
        }
        cout << "YES" << endl;
        for(int i = 0; i<n; i++) cout << ans[i]+1 << " ";
        cout << endl;
    }
}