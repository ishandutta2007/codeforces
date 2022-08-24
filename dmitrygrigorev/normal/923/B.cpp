#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n), t(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i < n; i++) cin >> t[i];
    int pref[n+1];
    pref[0] = 0;
    for (int i=0; i < n; i++) pref[i+1] = pref[i] + t[i];
    vector<int> die(n);
    for (int i=0; i < n; i++){
        int L = i-1, R = n;
        while (R-L>1){
            int M = (L+R)/2;
            int S = pref[M+1] - pref[i];
            if (S >= v[i]) R = M;
            else L = M;
        }
        die[i] = R;
    }
    vector<vector<int> > days(n);
    for (int i=0; i < n; i++) if (die[i] != n) days[die[i]].push_back(i);
    int S = 0, live = 0, R=0, snow=0;
    for (int i=0; i < n; i++){
        S += v[i], snow+=v[i];
        live++;
        S -= live * t[i];
        for (int j=0; j < days[i].size(); j++){
            int d = days[i][j];
            int potr = pref[i+1] - pref[d];
            S += potr - v[d];
            live--;
        }
        cout << snow-R-S << " ";
        R += (snow-R-S);
    }
    return 0;
}