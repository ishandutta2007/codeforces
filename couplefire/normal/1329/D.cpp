#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define MP make_pair
#define PB push_back
#define SZ(a) ((int)a.size())
typedef long long ll;
 
int T, N, mxc, t[400400], nxt[200200];
char s[200200];
set<int> all, h[28];
vector<pair<int, int>> res;
 
void u (int l, int r, int v) {
  // printf("update %d %d %d\n", l, r, v);
  for (l += N, r += N; l<r; l /= 2, r /= 2) {
    if (l&1) t[l++] += v;
    if (r&1) t[--r] += v;
  }
}
 
int q (int i) {
  int result = 0;
  // printf("query %d ", i);
  for (i += N; i >= 1; i /= 2) result += t[i];
  // printf("%d\n", result);
  return result;
}
 
void rem (int i) {
  all.erase(i);
  // printf("erase index %d\n", i);
  h[s[i]-'a'].erase(i);
}
 
void proc (int i, int j) {
  // join pair from i to j
  // printf("proc %d %d\n", i, j);
  // printf("%d %d\n", nxt[i], j);
  int na = q(nxt[i]), nb = q(j);
  res.PB(MP(1+na, 1+nb));
  // old indices from j onwards will be dropped by this amount
  u(j, N, -(nb-na+1));
  if (s[nxt[i]] == s[j]) rem(j);
  else rem(i), rem(j);
  nxt[i] = nxt[j];
}
 
int main () {
  scanf("%d", &T);
  fo(z, 0, T) {
    scanf("%s", s);
    N = (int) strlen(s);
 
    // reset variables
    fo(i, 0, N) {
      nxt[i] = i+1;
      t[i+N] = i;
      t[i] = 0;
    }
    res.clear();
    all.clear();
    fo(i, 0, 28) h[i].clear();
 
    fo(i, 0, N-1) {
      if (s[i] == s[i+1]) {
        all.insert(i);
        h[s[i] - 'a'].insert(i);
      }
    }
 
    mxc = 0;
    fo(i, 0, 28) {
      if (SZ(h[i]) > SZ(h[mxc])) {
        mxc = i;
      }
    }
 
    int expected = max(SZ(h[mxc]), (SZ(all)+1)/2);
 
    while (all.size()) {
 
      if (SZ(all) == 1) {
        int f = *all.begin();
        res.PB(MP(1+q(f),1+q(f)));
        u(f, N, -1);
        rem(f);
        break;
      }
 
      fo(i, 0, 28) {
        if (SZ(h[i]) > SZ(h[mxc])) {
          mxc = i;
        }
      }
      // mxc is mode
 
      // just take any pair with a big
      if (*h[mxc].begin() == *all.begin()) {
        int mni = N;
        fo(i, 0, 28) if (i != mxc && h[i].size()) {
          mni = min(mni, *h[i].begin());
        }
        if (mni == N) {
          proc(*h[mxc].begin(), *next(h[mxc].begin()));
        } else {
          auto x = *prev(h[mxc].lower_bound(mni));
          proc(x, mni);
        }
      } else {
        // match first big with previous guy
        int first_big = *h[mxc].begin();
        auto it = all.lower_bound(first_big);
        proc(*prev(it), *it);
      }
    }
 
    // assert(SZ(res) == expected);
    //
    if (q(N-1) >= 0) res.PB(MP(1, q(N-1)+1));
 
    printf("%d\n", SZ(res));
    for (auto i : res) printf("%d %d\n", i.first, i.second);
  }
  return 0;
}