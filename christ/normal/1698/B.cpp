#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
void solve () {
    int n,k; scanf ("%d %d",&n,&k);
    vector<int> a(n);
    for (int &i : a) scanf ("%d",&i);
    int ret = 0;
    for (int i = 1; i + 1 < n; i++) ret += a[i] > a[i-1] + a[i+1];
    if (k == 1) ret = (n-1)/2;
    printf ("%d\n",ret);
}
int main () { 
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}