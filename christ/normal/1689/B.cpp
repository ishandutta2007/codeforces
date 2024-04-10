#include<bits/stdc++.h>
using namespace std;
const int MN = 100+5;
char s[MN], t[MN];
void solve () {
    int n; scanf ("%d",&n);
    if (n == 1) {
        int v; scanf ("%d",&v);
        printf ("-1\n");
        return;
    }
    vector<int> p(n);
    for (int &i : p) scanf ("%d",&i);
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = 0; i < n-2; i++) {
        int v = *st.begin();
        if (v == p[i]) v = *next(st.begin());
        printf ("%d ",v);
        st.erase(v);
    }
    if (*st.begin() != p[n-2] && *st.rbegin() != p[n-1]) {
        printf ("%d %d\n",*st.begin(),*st.rbegin());
    } else if (*st.begin() != p[n-1] && *st.rbegin() != p[n-2]) {
        printf ("%d %d\n",*st.rbegin(),*st.begin());
    } else assert(false);
}
int main () {
    int _t; scanf ("%d",&_t);
    while (_t--) solve();
    return 0;
}