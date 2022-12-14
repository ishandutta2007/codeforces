#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int w, h, n;
multiset<int, greater<int> > V, H;
set<int> iv, ih;

void modi(multiset<int, greater<int> > &m, set<int> &v, int x) {
  set<int>::iterator it = v.lower_bound(x);
  set<int>::iterator jt = it;
  --jt;
  multiset<int, greater<int> >::iterator mt = m.find(*it - *jt);
  if (mt != m.end()) {
    m.erase(mt);
  }
  m.insert(x - *jt);
  m.insert(*it - x);
  v.insert(x);
}

int main() {
  scanf("%d %d %d", &w, &h, &n);
  
  iv.insert(0);
  iv.insert(w);
  V.insert(w);

  ih.insert(0);
  ih.insert(h);
  H.insert(h);

  for (int i = 0; i < n; ++i) {
    char tp[8];
    int x;
    scanf("%s %d", tp, &x);
    if (tp[0] == 'V') {
      modi(V, iv, x);
    } else {
      modi(H, ih, x);
    }
    printf("%lld\n", (long long) *V.begin() * *H.begin());
  }
  return 0;
}