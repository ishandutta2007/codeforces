#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct qel {
    uint64_t val, loc;
    const bool operator<(const qel other) const {
        if(val != other.val) return val > other.val;
        return loc > other.loc;
    }
};

priority_queue<qel> pq;

uint64_t val[150005], cumu;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(val, 255, sizeof val);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int v; cin >> v;
        pq.push({v, i});
    }
    cumu = 0;
    while(!pq.empty()) {
        qel top1 = pq.top(); pq.pop();
        if(pq.empty() || top1.val != pq.top().val) {
            // keep top1 out of the stack
            val[top1.loc] = top1.val;
            cumu++;
        } else {
            qel top2 = pq.top(); pq.pop(); // pop top2 out as well
            pq.push({top1.val*2, top2.loc});
        }
    }
    cout << cumu << endl;
    bool p = false;
    for(int i=0; i<n; i++) {
        if(val[i] == -1) continue;
        if(p) cout << ' ';
        cout << val[i];
        p = true;
    }
    cout << endl;
}