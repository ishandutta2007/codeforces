#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

struct pqel {
    int val; long long weight;
    const bool operator<(const pqel other) const {
        return weight > other.weight;
    };
};

int parent[100005];
long long dist[100005];

vector<pqel> elist[100005];

void dijk(int st) {
    priority_queue<pqel> pq;
    memset(parent, 255, sizeof parent);
    memset(dist, 1, sizeof dist);

    dist[st] = 0; parent[st] = st;
    pq.push({st, 0});
    while(!pq.empty()) {
        pqel top = pq.top(); pq.pop();
        int i = top.val;
        if(dist[i] < top.weight) continue;
        for(pqel e:elist[i]) {
            if(dist[i]+e.weight < dist[e.val]) {
                dist[e.val] = dist[i]+e.weight;
                parent[e.val] = i;
                pq.push({e.val, dist[e.val]});
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    while(m--) {
        int s, e, w; cin >> s >> e >> w;
        elist[s].push_back({e, w});
        elist[e].push_back({s, w});
    }
    dijk(1);
    stack<int> path;
    int loc = n;
    while(loc != -1 && loc != 1) {
        path.push(loc);
        loc = parent[loc];
    }
    if(loc == -1) { cout << -1 << endl; return 0; }
    cout << 1;
    while(!path.empty()) {
        cout << ' ' << path.top();
        path.pop();
    }
    cout << endl;
}