#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> pii;

void update(multiset<int>& M, multiset<pii>& C, int x) {
    while (C.size() && C.begin()->first <= x) {
        M.insert(C.begin()->second);
        C.erase(C.begin());
    }
}

int f(vector<pii> a, vector<pii> b, int x) {
    int res = 0;
    multiset<pii> A(a.begin(), a.end());
    multiset<pii> B(b.begin(), b.end());
    
    multiset<int> MA; update(MA, A, x);
    multiset<int> MB; update(MB, B, x);
    
    while (MA.size()) {
        ++res;
        x += *MA.rbegin(); MA.erase(--MA.end());
        update(MB, B, x);
        if (MB.size()) {
            ++res;
            x += *MB.rbegin(); MB.erase(--MB.end());
            update(MA, A, x);
        } else break;
    }
    
    return res;
}

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<pii> t[2];
    
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        t[x].push_back(pii(y, z));
    }
    
    sort(t[0].begin(), t[0].end());
    sort(t[1].begin(), t[1].end());
    
    cout << max(f(t[0], t[1], x), f(t[1], t[0], x)) << endl;
}

int main() {
    solve();
    return 0;
}