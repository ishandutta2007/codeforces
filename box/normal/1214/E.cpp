#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
    int id, i, dist;
    const bool operator<(const point other) const {
        return dist > other.dist;
    }
};

vector<point> Chain;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        int v; cin >> v;
        Chain.push_back({2*i-1, i, v});
    }
    sort(Chain.begin(), Chain.end());
    for(int i=0; i<n-1; i++) cout << Chain[i].id << ' ' << Chain[i+1].id << endl;
    for(int i=0; i<n; i++) {
        int ctp = i+Chain[i].dist-1;
        cout << Chain[ctp].id << ' ' << 2*Chain[i].i << endl;
        if(ctp == Chain.size()-1) Chain.push_back({2*Chain[i].i, -1, -1});
    }
}