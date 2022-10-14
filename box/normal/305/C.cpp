#include <iostream>
#include <set>
using namespace std;
set<int> s;
void add(int i) {
    auto pt = s.find(i);
    if(pt != s.end()) {
        s.erase(pt);
        add(i+1);
    } else s.insert(i);
}

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int v; cin >> v;
        add(v);
    }
    int mx = -1;
    for(int i:s)
        if(i > mx) mx = i;
    cout << (mx+1-s.size()) << endl;
}