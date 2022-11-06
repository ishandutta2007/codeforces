#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("1.inp" ,"r")) freopen("1.inp", "r", stdin);

    int n, k;
    cin >> n >> k;

    vector < vector < pair < int, int > > > seg(200005);
    for(int i = 1; i <= n; ++i){
        int l, r; cin >> l >> r;
        seg[l].push_back(make_pair(r, i));
    }

    set < pair < int, int > > points;

    vector < int > ans;
    for(int i = 0; i < 200005; ++i) {
        while(!points.empty() && points.begin() -> first < i) points.erase(points.begin());
        for(auto x : seg[i]) points.insert(x);
        while(points.size() > k) {
            ans.push_back(points.rbegin() -> second);
            points.erase(*points.rbegin());
        }
    }

    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}