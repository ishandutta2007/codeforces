#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 1<<17;

struct str {
  int l, r, ind;
  str (int l, int r, int ind) : l(l), r(r), ind(ind) {}
  str () {}
} ul[MAX], cov[MAX];

bool ManjiSort(str a, str b)
{
  if (a.l != b.l)
    return a.l < b.l;
  if (a.r != b.r)
    return a.r < b.r;
  return a.ind < b.ind;
}

bool operator < (str a, str b)
{
  if (a.r != b.r)
    return a.r < b.r;
  if (a.l != b.l)
    return a.l < b.l;
  return a.ind < b.ind;
}

struct event {
  int st, vrijeme;
  str val;
  event (int st, int vrijeme, str val) : st(st), vrijeme(vrijeme), val(val) {}
  event () {}
} ev[2*MAX];

bool operator < (event a, event b)
{
  if (a.vrijeme != b.vrijeme)
    return a.vrijeme < b.vrijeme;
  if (a.st != b.st)
    return a.st < b.st;
  return a.val < b.val;
}

set <str> S;
int smije[MAX];
int rje[MAX];

int main()
{
  int brul, brcov, rez=0;

  scanf("%d", &brul);

  for (int i=0; i<brul; i++) {
    scanf("%d%d", &ul[i].l, &ul[i].r);
    ul[i].ind = i;
  }
  
  scanf("%d", &brcov);

  for (int i=0; i<brcov; i++) {
    scanf("%d%d%d", &cov[i].l, &cov[i].r, &smije[i]);
    cov[i].ind = i;
    ev[2*i] = event(1, cov[i].l, cov[i]);
    ev[2*i+1] = event(0, cov[i].r+1, cov[i]);
  }

  sort(ul, ul+brul, ManjiSort);
  sort(ev, ev+2*brcov);

  for (int i=0, indev=0; i<brul; i++) {
    for (; indev < 2*brcov && ev[indev].vrijeme <= ul[i].l; indev++) {
      if (ev[indev].st)
        S.insert(ev[indev].val);
      else if (S.find(ev[indev].val) != S.end())
        S.erase(ev[indev].val);
    }

    set <str> :: iterator it;

    it = S.lower_bound(str(-1, ul[i].r, -1));
    if (it != S.end()) {
      smije[it->ind]--;
      rje[ul[i].ind] = it->ind;
      if (!smije[it->ind])
        S.erase(it);
    }
    else
      rez = -1;
  }

  if (rez == -1)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i=0; i<brul; i++)
      printf("%d ", rje[i]+1);
    printf("\n");
  }

  return 0;
}