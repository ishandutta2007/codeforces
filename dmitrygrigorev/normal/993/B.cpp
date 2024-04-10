#include <bits/stdc++.h>
#define int long long
using namespace std;
int INF = 1e9;
signed main()
{
    //freopen("1.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a, b;
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    for (int i=0; i < m; i++){
        int x, y;
        cin >> x >> y;
        b.push_back({x, y});
    }
    set<int> mayb;
    for (int i=0; i < a.size(); i++){
        int x, y;
        x = a[i].first, y = a[i].second;
        set<int> unn;
        for (int j=0; j < b.size(); j++){
            int e = b[j].first, f = b[j].second;
            if (e==x && f==y) continue;
            if (f==x && e==y) continue;
            if (e==x || f==x) unn.insert(x);
            if (e==y || f==y) unn.insert(y);
        }
        if (unn.size() == 2){
            cout << -1;
            return 0;
        }
        if (unn.size()) mayb.insert(*unn.begin());
    }
    bool able = false;
    for (int i=0; i < b.size(); i++){
        int x, y;
        x = b[i].first, y = b[i].second;
        set<int> unn;
        for (int j=0; j < a.size(); j++){
            int e = a[j].first, f = a[j].second;
            if (e==x && f==y) continue;
            if (f==x && e==y) continue;
            if (e==x || f==x) unn.insert(x);
            if (e==y || f==y) unn.insert(y);
        }
        if (unn.size() == 2){
            cout << -1;
            return 0;
        }
    }
    if (mayb.size()<=1) cout << *mayb.begin();
    else cout << 0;
    return 0;
}