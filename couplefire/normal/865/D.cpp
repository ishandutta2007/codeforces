#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, ans;
priority_queue<int, vector<int>, greater<>> pq;

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int p; cin >> p;
        pq.push(p);
        if(!pq.empty() && pq.top() < p){
            ans += p-pq.top(); pq.pop(); pq.push(p);
        }
    }
    cout << ans << endl;
}