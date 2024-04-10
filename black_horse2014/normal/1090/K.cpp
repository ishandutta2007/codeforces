#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;
const int Q = 1e9 + 9;

int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    map<pair<int, pair<int, int> >, vector<int> > H;
    for (int i = 0; i < n; i++) {
        string s, t; cin >> s >> t;
        int state = 0;
        for (int j = 0; j < t.length(); j++) state |= 1 << (t[j] - 'a');
        int lastp = 0, lastq = 0, curp = 0, curq = 0;
        for (int j = 0; j < s.length(); j++) {
            int color = s[j] - 'a';
            curp = (curp * 37LL + color + 1) % P;
            curq = (curq * 37LL + color + 1) % Q;
            if (~state >> color & 1) lastp = curp, lastq = curq;
        }
        H[make_pair(state, make_pair(lastp, lastq))].push_back(i + 1);
    }
    cout << H.size() << endl;
    for (auto &t : H) {
        auto &v = t.second;
        cout << v.size();
        for (int x : v) cout << ' ' << x;
        cout << endl;
    }
    return 0;
}