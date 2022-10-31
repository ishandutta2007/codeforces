#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int TOUR = 1<<20;

void Stavi(int t[2*TOUR], int pos, int val)
{
  for (pos += TOUR; pos; pos /= 2)
    t[pos] = max(t[pos], val);
}

int Vrati(int t[2*TOUR], int pos, int lo, int hi, int begin, int end)
{
  if (lo >= end || hi <= begin)
    return 0;
  if (lo >= begin && hi <= end)
    return t[pos];
  return max(Vrati(t, 2*pos+0, lo, (lo+hi)/2, begin, end),
             Vrati(t, 2*pos+1, (lo+hi)/2, hi, begin, end) );  
}

int maxl[2*TOUR], maxr[2*TOUR];
int lc[TOUR], rc[TOUR];
int unutra[TOUR], bio[TOUR];
int n, ind=2;
vector <pair<int, int> > P[TOUR];

void Dfs(int node, int kraj)
{
  if (maxl[node+TOUR] >= ind) {
    lc[node] = ind++;
    Dfs(lc[node], maxl[node+TOUR]);
  }
  
  if (max(kraj, maxr[node+TOUR]) >= ind) {
    rc[node] = ind++;
    Dfs(rc[node], max(kraj, maxr[node+TOUR]));
  }
}

int Prov(int node)
{
  int ret=0;
  
  bio[node] = 1;
  unutra[node] = 1;
  for (int i=0; i<(int) P[node].size(); i++)
    if (unutra[P[node][i].first] != P[node][i].second)
      ret = 1;
  
  if (lc[node])
    ret |= Prov(lc[node]);
  unutra[node] = 2;
  if (rc[node])
    ret |= Prov(rc[node]);

  unutra[node] = 0;
  return ret;
}

int Provjera()
{
  if (Prov(1))
    return 1;
  for (int i=1; i<=n; i++)
    if (!bio[i])
      return 1;
  return 0;
}

void InOrd(int node)
{
  if (lc[node])
    InOrd(lc[node]);
  printf("%d ", node);
  if (rc[node])
    InOrd(rc[node]);
}

int main()
{
  int q, ne=0;

  scanf("%d%d", &n, &q);
  
  for (int i=0; i<q; i++) {
    int a, b, st=1;
    char s[10];
    scanf("%d%d%s", &a, &b, s);
    if (s[0] == 'L')
      Stavi(maxl, a, b);
    else {
      Stavi(maxr, a, b);
      st = 2;
    }
    if (b <= a)
      ne = 1;
    P[b].push_back(make_pair(a, st));
  }

  Dfs(1, n);
  if (ne || Provjera())
    printf("IMPOSSIBLE\n");
  else {
    InOrd(1);
    printf("\n");
  }

  return 0;
}