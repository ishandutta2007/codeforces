#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s;
    cin >> n >> s;
    int L = 0, R = n-1;
    if (s < 1+(n-1)*2){
        cout << "No";
        return 0;
    }
    if (s > n*(n+1)/2){
        cout << "No";
        return 0;
    }
    while (R-L>1){
        int M = (L+R)/2;
        int sum = 1;
        int step = 2, mn = M, vrt = n-1;
        while (vrt > 0){
            if (vrt <= mn){
                sum += step*vrt;
                break;
            }
            vrt -= mn;
            sum += step*mn;
            mn *= M;
            step++;
        }
        if (sum < s){
            R = M;
        }
        else L = M;
    }
    vector<int> father, lvl;
    father.push_back(-1);
    lvl.push_back(1);
    for (int i=1; i < n; i++){
        father.push_back((i-1)/L);
        lvl.push_back(lvl[father.back()]+1);
    }
    int S = 0;
    for (int i=0; i < n; i++) S += lvl[i];
    int u2=n-1;
    vector<vector<pair<int, int> > > kek(n);
    for (int i=0; i < n; i++) kek[lvl[i]-1].push_back({i, L});
    int i = 0, j = 0;
    //cout << L << endl;
    bool rev = true;
    while (S > s){
        if (rev) reverse(kek[i].begin(), kek[i].end());
        rev = false;
        int u1 = kek[i][j].first;
        int diff = lvl[u2] - lvl[u1]-1;
        if (S-s <= diff){
            u1 = kek[i].back().first;
            int steps = diff - (S-s);
            for (int j=0;j<steps;j++) u1 = L*u1+1;
            father[u2] = u1;
            break;
        }
        else{
            S -= diff;
            father[u2] = u1;
            lvl[u2] = lvl[u1]+1;
            kek[i+1].push_back({u2, 0});
            u2--;
            if (kek[i][j].second != L){
                kek[i][j].second++;
                continue;
            }
            j++;
            if (j >= kek[i].size()){
                i++, j=0;
                rev=true;
            }
        }
       // cout << i << " " << j << " " << u1 << " " << u2 << " " << S << endl;
    }
    cout << "Yes" << endl;
    for (int i=1; i < n; i++) cout << father[i] + 1 << " ";
    return 0;
}