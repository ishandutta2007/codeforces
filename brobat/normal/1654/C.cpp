#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> occ;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            occ[x]++;
            sum += x;
        }
        priority_queue<int> pq;
        pq.push(sum);
        bool pos = true;
        int done = 0;
        while((int)pq.size() < n && (done < n)) {
            int curr = pq.top();
            pq.pop();
            if(occ[curr] > 0) {
                occ[curr]--;
                done++;
            } else {
                pq.push(curr/2);
                pq.push(curr - curr/2);
            }
        }
        while(!pq.empty()) {
            int curr = pq.top();
            pq.pop();
            if(occ[curr] == 0) {
                pos = false;
            } else {
                occ[curr]--;
            }
        }
        cout << (pos ? "YES" : "NO") << endl;
    }
    
    return 0;
}