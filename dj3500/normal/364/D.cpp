#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define mp make_pair
#define ll long long
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define ALL(t) t.begin(),t.end()

#define N 1000007
int n;
ll t[N], best;

int main () {
   scanf("%d", &n);
   srand(time(0));
   FOR(i,n) scanf("%I64d", &t[i]);
   clock_t startTime = clock();
   best = 1;
   vector<pair<ll,int> > divs;
   while (clock() - startTime < 1.0 * CLOCKS_PER_SEC) {
      const ll x = t[(rand() * RAND_MAX + rand()) % n]; // Windows on CF...
      divs.clear();
      for (int d = 1; 1LL*d*d <= x; ++d) if (x % d == 0) {
         divs.pb(mp(d,0));
         divs.pb(mp(x/d,0));
      }
      sort(ALL(divs));
      divs.erase(unique(ALL(divs)),divs.end());
      
      FOR(i,n) lower_bound(ALL(divs), mp(__gcd(x,t[i]),0))->se++;
      FOR(i,SZ(divs)) FOR(j,i) if (divs[i].fi % divs[j].fi == 0) divs[j].se += divs[i].se;
      for (auto it : divs) if (2 * it.se >= n) best = max(best, it.fi);
   }
   printf("%lld\n", best);
}