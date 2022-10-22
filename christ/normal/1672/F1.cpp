#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
void solve () {
    int n; scanf ("%d",&n);
    vector<int> a(n);
    vector<vector<int>> with(n+1);
    set<int> nonempty;
    for (int i = 0; i < n; i++) {
        scanf ("%d",&a[i]);
        with[a[i]].push_back(i);
        nonempty.insert(a[i]);
    }
    vector<int> b(n);
    while (!nonempty.empty()) {
        vector<int> to_del;
        int fst = -1, lst = -1;
        for (int i : nonempty) {
            if (!~fst) fst = i;
            else {
                int pos = with[i].back();
                b[pos] = lst;
                with[i].pop_back();
                if (with[i].empty()) to_del.push_back(i);
            }
            lst = i;
        }
        int pos = with[fst].back();
        b[pos] = lst;
        with[fst].pop_back();
        if (with[fst].empty()) to_del.push_back(fst);
        for (int i : to_del) nonempty.erase(i);
    }
    for (int i : b) printf ("%d ",i);
    printf ("\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}