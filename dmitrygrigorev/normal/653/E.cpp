#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
vector<set<int> > v;
set<int> unused;
int n, m, k, counter;
void dfs(int vertex){
    auto it = unused.upper_bound(vertex-1);
    unused.erase(it);
    int last = -1;
    while (true){
        auto it = unused.upper_bound(last);
        if (it == unused.end()) break;
        int S = *it;
        last = S;
        if (v[vertex].count(S)) continue;
        if (vertex==0) counter++;
        dfs(S);
    }
}
signed main(){
    cin >> n >> m >> k;
    for (int i=0; i < n; i++){
        unused.insert(i);
        set<int> ms;
        v.push_back(ms);
    }
    for (int i=0; i < m; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        v[l].insert(r);
        v[r].insert(l);
    }
    if (n - 1 - v[0].size() < k){
        cout << "impossible" << endl;
        return 0;
    }
    counter = 0;
    dfs(0);
    if (unused.size() == 0 && counter <= k) cout << "possible" << endl;
    else cout << "impossible" << endl;
    return 0;
}