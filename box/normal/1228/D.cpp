#include <bits/stdc++.h>
using namespace std;

struct sat {
    vector<int> to;
    int id;
    const bool operator<(const sat other) const {
        return to < other.to;
    }
};

sat t[100005];
int as[100005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) t[i].id = i;
    while(m--) {
        int v,e; cin >> v >> e;
        t[v].to.push_back(e); t[e].to.push_back(v);
    }
    for(int i=1; i<=n; i++) {
        if(t[i].to.size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        sort(t[i].to.begin(), t[i].to.end());
    }
    sort(t+1, t+n+1);
    int cnt = 2;
    as[t[1].id] = 1;
    for(int i=2; i<=n; i++) {
        if(t[i].to != t[i-1].to) as[t[i].id] = cnt++;
        else as[t[i].id] = as[t[i-1].id];
    }
    if(cnt != 4) {
        cout << -1 << endl;
        return 0;
    }
    for(int i=1; i<=n; i++) {
        if(i != 1) cout << ' ';
        cout << as[i];
    }
    cout << endl;
}