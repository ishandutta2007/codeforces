#include <bits/stdc++.h>
using namespace std;
#define int long long

int cost(int x, int y) {
        int quo = x / y;
        int rem = x % y;
        return rem*(quo+1)*(quo+1) + (y-rem)*quo*quo;
    }

struct Pair {
    int x, y;

    bool operator <(const Pair & o) const {
        // we want the one which can save MOST cost by one more split.
        return cost(x, y) - cost(x, y + 1) < cost(o.x, o.y) - cost(o.x, o.y + 1);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    priority_queue<Pair> pq;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(Pair{x, 1});
    }
    for(int i = 0; i < k - n; i++) {
        Pair curr = pq.top();
        pq.pop();
        curr.y++;
        pq.push(curr);
    }
    int ans = 0;
    while(!pq.empty()) {
        Pair curr = pq.top();
        pq.pop();
        // cout << curr.x << " " << curr.y << '\n';
        int quo = curr.x / curr.y;
        int rem = curr.x % curr.y;
        for(int i = 0; i < curr.y; i++) {
            if(i < rem) {
                ans += (quo + 1) * (quo + 1);
            } else {
                ans += quo * quo;
            }
        }
    }
    cout << ans;
    
    return 0;
}