#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int TOUR = 1<<18, INF = 0x3f3f3f3f;

struct tournament {
  vector <int> t[2*TOUR];

  void insert(int pos, int lo, int hi, int begin, int end, int val) {
    if (lo >= end || hi <= begin)
      return;
    if (lo >= begin && hi <= end) {
      t[pos].push_back(val);
      return;
    }

    insert(2*pos+0, lo, (lo+hi)/2, begin, end, val);
    insert(2*pos+1, (lo+hi)/2, hi, begin, end, val);
  }

  void insert(int begin, int end, int val) {
    insert(1, 0, TOUR, begin, end, val);
  }

  vector <int> query(int pos) {
    vector <int> R;

    pos += TOUR;
    for (; pos; pos /= 2) {
      for (int j=0; j<(int) t[pos].size(); j++)
        R.push_back(t[pos][j]);

      t[pos].clear();
    }
    

    return R;
  }
} T;

int st[TOUR], aa[TOUR][2];
int uroot[TOUR], urank[TOUR], l[TOUR], r[TOUR];
vector <int> V;

int Find(int x)
{
  if (uroot[x] == -1)
    return x;
  return uroot[x] = Find(uroot[x]);
}

void Merge(int a, int b)
{
  a = Find(a);
  b = Find(b);

  if (a == b)
    return;

  l[a] = l[b] = min(l[a], l[b]);
  r[a] = r[b] = max(r[a], r[b]);

  if (urank[a] > urank[b])
    uroot[b] = a;
  else if (urank[b] > urank[a])
    uroot[a] = b;
  else {
    uroot[b] = a;
    urank[a]++;
  }
}

void Spoji(int ind, int poz)
{
  vector <int> R = T.query(poz);

  for (int i=0; i<(int) R.size(); i++)
    Merge(R[i], ind);
}

int main()
{
  int n, ind=1;

  scanf("%d", &n);

  memset(uroot, -1, sizeof uroot);

  for (int i=0; i<n; i++) {
    scanf("%d%d%d", &st[i], &aa[i][0], &aa[i][1]);
    if (st[i] == 1)
      for (int j=0; j<2; j++)
        V.push_back(aa[i][j]);
  }

  sort(V.begin(), V.end());

  for (int i=0; i<n; i++)
    if (st[i] == 1)
      for (int j=0; j<2; j++)
        aa[i][j] = lower_bound(V.begin(), V.end(), aa[i][j]) - V.begin();

  for (int i=0; i<n; i++) {

    if (st[i] == 1) {
      int ll = aa[i][0], rr = aa[i][1];

      l[ind] = ll;
      r[ind] = rr;

      Spoji(ind, ll);
      Spoji(ind, rr);
      T.insert(l[Find(ind)] + 1, r[Find(ind)], ind);

      ind++;
    }
    else {
      int a = aa[i][0], b = aa[i][1];

      a = Find(a);
      b = Find(b);

      if (a == b || (l[a] >= l[b] && r[a] <= r[b]))
        printf("YES\n");
      else
        printf("NO\n");
    }
  }

  return 0;
}