#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    map<int, vector<int> > kek;
    for (int i=0; i <= n; i++) kek[i] = {};
    for (int i=0; i < n; i++){
        kek[v[i]].push_back(i);
    }
    vector<int> ans(n);
    int t = 0;
    for (auto it=kek.begin(); it != kek.end(); it++){
        pair<int, vector<int> > p = *it;
        if (p.second.size() == 0) continue;
        int X = n - p.first;
        if (p.second.size() % X != 0){
            cout << "Impossible";
            return 0;
        }
        for (int i=0; i < p.second.size(); i += X){
            for (int j=i; j < i+X; j++) ans[p.second[j]] = t;
            t++;
        }
    }
    cout << "Possible" << endl;
    for (int i= 0; i < n; i++) cout << ans[i]+1 << " ";
    return 0;
}