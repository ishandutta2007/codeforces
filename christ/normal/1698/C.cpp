#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
void solve () {
    int n; scanf ("%d",&n);
    vector<int> v(n);
    for (int &i : v) scanf ("%d",&i);
    sort(v.begin(),v.end());
    for (int i = 2; i < n-2; i++) if (v[i] != 0) {
        printf ("NO\n");
        return;
    }
    vector<int> new_v;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i >= 2 && i < n-2) {
            if (cnt < 3) {
                new_v.push_back(v[i]);
                ++cnt;
            }
        } else {
            new_v.push_back(v[i]);
        }
    }
    v = new_v;
    n = (int)v.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                int x = v[i] + v[j] + v[k];
                bool found = false;
                for (int l = 0; l < n; l++) found |= v[l] == x;
                if (!found) {
                    printf ("NO\n");
                    return;
                }
            }
        }
    }
    printf ("YES\n");
}
int main () { 
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}