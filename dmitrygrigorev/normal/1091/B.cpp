#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int> > pts, pds;
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        pts.push_back({x, y});
    }
    for (int i=0; i < n; i++){
        int x, y;
        cin >> x >> y;
        pds.push_back({x, y});
    }
    sort(pts.begin(), pts.end());
    for (int i=0; i < n; i++){
        pair<int, int> cand = {pts[0].first + pds[i].first, pts[0].second + pds[i].second};
        vector<pair<int, int> > kek;
        for (int j=0; j < n; j++){
            pair<int, int> p = {cand.first - pds[j].first, cand.second - pds[j].second};
            kek.push_back(p);
        }
        sort(kek.begin(), kek.end());
        bool ab = true;
        for (int p=0;p<n;p++) if (kek[p] != pts[p]) ab=false;
        if (ab){
            cout << cand.first << " " << cand.second << endl;
            return 0;
        }
    }
    return 0;
}