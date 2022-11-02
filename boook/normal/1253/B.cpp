#include <bits/stdc++.h>
using namespace std;

const int maxn = 100090;

int n, x[maxn];

int main(){
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n;
    
    for (int i = 1; i <= n; i ++) cin >> x[i];

    int done = 0;
    set<int> cc, in;
    vector<int> ans;
    for (int i = 1; i <= n; i ++) {
        if (x[i] > 0){
            if (cc.count(-x[i]) || in.count(x[i]))
                return cout << -1 << endl, 0;
            cc.insert(x[i]);
            in.insert(x[i]);
        }
        else {
            if (cc.count(-x[i]) == 0)
                return cout << -1 << endl, 0;
            cc.erase(-x[i]);
        }
        if (cc.size() == 0) {
            in.clear();
            ans.emplace_back(i - done);
            done = i;
        }
    }
    if (cc.size() != 0)
        return cout << -1 << endl, 0;

    cout << ans.size() << endl;
    for (auto to : ans) cout << to << " ";  cout << endl;
    return 0;
}