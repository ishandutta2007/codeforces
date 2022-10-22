#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
void solve () {
    int n; scanf ("%d",&n);
    vector<int> a(n);
    int sum = 0;
    for (int &i : a) scanf ("%d",&i), sum += i-1;
    printf (sum % 2 ? "errorgorn\n" : "maomao90\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}