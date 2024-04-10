#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cost[1005];
bool dest[1005];
vector<int> edgel[1005];
vector<int> order;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> cost[i];
        order.push_back(i);
    }
    for(int i=1; i<=m; i++) {
        int s, e; cin >> s >> e;
        edgel[s].push_back(e);
        edgel[e].push_back(s);
    }
    sort(order.begin(), order.end(), [](const int a, const int b) {
        return cost[a] > cost[b];
    });
    long long tcost = 0;
    for(int i:order) {
        for(int ch:edgel[i]) if(!dest[ch]) tcost += cost[ch];
        dest[i] = true;
    }
    cout << tcost << endl;
}