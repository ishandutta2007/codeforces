#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

using ll = long long;

map<int, bool> start;

bool merge(int l, int r) {
    auto it_l = start.find(l), it_r = start.find(r);
    int n_one = 0, n_zero = 0;
    for(auto it = it_l; it != it_r; it++) {
        if(it->second) {
            n_one += next(it)->first - it->first;
        } else {
            n_zero += next(it)->first - it->first;
        }
    }
    if(n_one == n_zero) {
        return 0;
    }
    start.erase(it_l, it_r);
    start[l] = n_one > n_zero;
    return 1;
}

void split(int index) {
    auto it = start.lower_bound(index);
    if(it->first != index) {
        int tmp = prev(it)->second;
        start[index] = tmp;
    }
}

int l[200000], r[200000];

void solve() {
    int n, q;
    string s, t;
    cin >> n >> q >> s >> t;
    start.clear();
    start[0] = t[0] - '0';
    for(int i = 1; i < n; i++) {
        if(t[i] != t[i - 1]) {
            start[i] = t[i] - '0';
        }
    }
    start[n] = 0;
    for(int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
    }
    for(int i = q - 1; i >= 0; i--) {
        l[i]--;
        split(l[i]);
        split(r[i]);
        if(!merge(l[i], r[i])) {
            cout << "NO\n";
            return;
        }
    }
    auto it = start.begin();
    for(int i = 0; i < n; i++) {
        if(i == next(it)->first) {
            it++;
        }
        if(s[i] == '1' ^ (it->second)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}