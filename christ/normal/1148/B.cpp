#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int min (int a, int b) {return a < b ? a : b;}
inline int max (int a, int b) {return a > b ? a : b;}
inline int max (int a, int b, int c) {return max (a,max(b,c));}
inline ll min (ll a, ll b) {return a < b ? a : b;}
inline int abs (int a) {return a < 0 ? -a : a;}
vector<int> af, bf;
int main() {
    int n,m,ta,tb,k;
    scanf ("%d %d %d %d %d",&n,&m,&ta,&tb,&k);
    if (k >= min(n,m)) return !printf ("-1\n");
    af.resize(n); bf.resize(m);
    for (auto &a : af) scanf ("%d",&a);
    for (auto &a : bf) scanf ("%d",&a);
    sort(af.begin(),af.end());
    sort(bf.begin(),bf.end());
    for (int x = 0; x <= k; x++) {
      if (af[x]+ta > bf[m-1-(k-x)]) return !printf ("-1\n");
    }
    int best = 0;
    for (int x = 0; x <= k; x++) {
      auto cur = lower_bound(bf.begin(),bf.end(),af[x]+ta);
      if (cur + (k-x) >= bf.end()) return !printf ("-1\n");
      else {
        int pos = cur - bf.begin();
        best = max(best,bf[pos+(k-x)]+tb);
      }
    }
    printf ("%d\n",best);
    return 0;
}