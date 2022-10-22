#include<bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
void solve () {
    int n; scanf ("%d",&n);
    vector<int> v(n), ret(n);
    int fst = 0;
    for (int &i : v) scanf ("%d",&i);
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i] != v[i-1]) fst = i;
        if (i + 1 < n && v[i] == v[i+1]) ret[i] = i+1;
        else ret[i] = fst;
    }
    for (int i = 0; i < n; i++) if (ret[i] == i) {
        printf ("-1\n");
        return;
    }
    for (int i = 0; i < n; i++) printf ("%d ",ret[i]+1);
    printf ("\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}