#include <iostream>
#include <map>
#include <utility>
using namespace std;

map<int, long long> sx, sy;
map<pair<int, int>, long long> sp;

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        sx[x]++;
        sy[y]++;
        sp[make_pair(x, y)]++;
    }
    long long tot = 0;
    for(auto& i:sx) tot += (i.second*(i.second-1));
    for(auto& i:sy) tot += (i.second*(i.second-1));
    for(auto& i:sp) tot -= (i.second*(i.second-1));
    cout << tot/2 << endl;
}