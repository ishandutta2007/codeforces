#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
void solve () {
   int n; scanf ("%d",&n);
   vector<int> v(n);
   for (int &i : v) scanf ("%d",&i);
   int m; scanf ("%d",&m);
   vector<int> w(m);
   for (int &i : w) scanf ("%d",&i);
   int amax = *max_element(v.begin(),v.end());
   int bmax = *max_element(w.begin(),w.end());
   if (amax > bmax) {
    printf ("Alice\nAlice\n");
   } else if (bmax > amax) {
    printf ("Bob\nBob\n");
   } else {
    printf ("Alice\nBob\n");
   }
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}