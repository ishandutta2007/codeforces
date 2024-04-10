#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = (1<<16) + 5;

struct str {
  int deg, val, ind;
  str (int deg, int val, int ind) : deg(deg), val(val), ind(ind) {}
  str () {}
};

bool operator < (str a, str b)
{
  if (a.deg != b.deg)
    return a.deg < b.deg;
  return a.ind < b.ind;
}

int tval[MAX];
int tdeg[MAX];
set <str> S;

int main()
{
  int n, bredge=0;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d%d", &tdeg[i], &tval[i]); bredge += tdeg[i];
    S.insert(str(tdeg[i], tval[i], i));
  }

  printf("%d\n", bredge / 2);

  for (; !S.empty(); ) {
    set <str> :: iterator it = S.begin();
    if (it->deg == 1) {
      int nnode = tval[it->ind];
      printf("%d %d\n", it->ind, nnode);
      S.erase(str(tdeg[nnode], tval[nnode], nnode));
      tval[nnode] ^= it->ind;
      tdeg[nnode]--;
      S.insert(str(tdeg[nnode], tval[nnode], nnode));
    }
    S.erase(it);
  }

  return 0;
}