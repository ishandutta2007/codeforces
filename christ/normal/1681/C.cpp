#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
void solve () {
    int n; scanf ("%d",&n);
    vector<array<int,2>> v(n);
    for (int i = 0; i < n; i++) scanf ("%d",&v[i][0]);
    for (int i = 0; i < n; i++) scanf ("%d",&v[i][1]);
    vector<array<int,2>> ret;
    for (int i = 0; i < n; i++) {
        array<int,3> mn;
        mn = {INT_MAX,0,0};
        for (int j = i; j < n; j++) mn = min(mn,array<int,3>{v[j][0],v[j][1],j});
        int j = mn[2];
        for (int k = j-1; k >= i; k--) {
            swap(v[k],v[k+1]);
            ret.push_back({k,k+1});
        }
    }
    for (int i = 1; i < n; i++) {
        if (v[i][0] < v[i-1][0] || v[i][1] < v[i-1][1]) {
            printf ("-1\n");
            return;
        }
    }
    printf ("%d\n",(int)ret.size());
    for (auto [u,v] :ret) printf ("%d %d\n",u+1,v+1);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}