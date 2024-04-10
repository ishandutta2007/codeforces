#include <iostream>
#include <set>
#include <vector>
#include <utility>
using namespace std;

set<pair<int, int>> num;
vector<pair<int, int>> order;

int main() {
    int n, k; cin >> n >> k;
    if(n == 1) {
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    for(int i=0; i<n; i++) {
        int v; cin >> v;
        num.insert(make_pair(v, i+1));
    }
    int bestk = (--num.end())->first - num.begin()->first, bestm = 0;
    for(int i=1; i<=k; i++) {
        if(bestk == 0) break;
        auto l = *(--num.end()), s = *num.begin();
        num.erase(--num.end()); num.erase(num.begin());
        order.push_back(make_pair(l.second, s.second));
        l.first--; s.first++;
        num.insert(l); num.insert(s);
        if((--num.end())->first - num.begin()->first < bestk) {
            bestm = i;
            bestk = (--num.end())->first - num.begin()->first;
        }
    }
    cout << bestk << ' ' << bestm << endl;
    for(int i=0; i<bestm; i++) {
        cout << order[i].first << ' ' << order[i].second << endl;
    }
}