#include <bits/stdc++.h>

using namespace std;

int divv(int a, int b) {
    return (a + b - 1) / b;
}

int Solve(vector<int> have, int from1, int to1, int from2, int to2) {
    cerr << from1 << "->" << to1 << " " << from2 << "->" << to2 << endl;

    set<pair<int, int>> pair_set;
    pair_set.insert({divv(to1, from1), divv(to2, from2)});
    
    if (pair_set.find({1, 1}) != pair_set.end()) {
        return 0;
    }

    for (int ans = 0; ans < have.size(); ++ans) {
        
        auto Transform = [](set<pair<int, int>> s, int x) {
            set<pair<int, int>> ret;
            for (auto p : s) {
                ret.insert({divv(p.first, x), p.second});
                ret.insert({p.first, divv(p.second, x)});
            }
            return ret;
        };

        pair_set = Transform(pair_set, have[ans]);
        if (pair_set.find({1, 1}) != pair_set.end()) 
            return ans + 1;
    }
 
    return 5000;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;

    vector<int> V(n);
    for (auto &x : V) cin >> x;

    sort(V.rbegin(), V.rend());
    int ans = min(Solve(V, h, a, w, b), Solve(V, h, b, w, a));

    if (ans > 200) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
	
	return 0;
}