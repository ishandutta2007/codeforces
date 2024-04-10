#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MN = 2e5+1, INF = 2e9;
int freq[MN];
void solve () {
    int n;
    scanf ("%d",&n);
    vector<int> a(n), b(n), diff(n);
    for (auto &au : a) scanf ("%d",&au);
    for (auto &au : b) scanf ("%d",&au);
    int boi = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        diff[i] = b[i]-a[i];
    }
    for (int i = 0; i < n; i++) if (diff[i] < 0) {printf ("NO\n"); return;}
    int wot = -1, first = INT_MAX, last = -1;
    for (int i = 0; i < n; i++) if (diff[i]) {
        wot = diff[i];
        last = i;
        first = min(first,i);
    }
    if (wot == -1) {printf ("YES\n"); return;}
    for (int i = first; i <= last; i++) a[i] += wot;
    for (int i = 0; i < n; i++) if (a[i] != b[i]) {printf ("NO\n"); return;}
    printf ("YES\n");
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}
//11649,6796