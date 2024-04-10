#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

typedef long long ll;
const int MAX = 200100;

struct toc {
  int ind;
  int repx, repy;
} p[MAX];

bool operator < (toc a, toc b)
{
  if (a.repx != b.repx)
    return a.repx > b.repx;
  return a.repy > b.repy;
}

int Ccw(toc a, toc b, toc c)
{
  ll tmp = (ll) b.repx * c.repx * (a.repy * c.repy - a.repy * b.repy) + 
           (ll) a.repx * c.repx * (a.repy * b.repy - b.repy * c.repy) + 
           (ll) a.repx * b.repx * (b.repy * c.repy - a.repy * c.repy);

  if (tmp < 0)
    return -1;
  if (tmp > 0)
    return 1;
  return 0;
}

int pocx[MAX], pocy[MAX];
map <pair<int, int>, int> M;
int maxx[MAX], maxy[MAX];
int rje[MAX];
int l[MAX], r[MAX];
vector <toc> V;

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d%d", &p[i].repx, &p[i].repy);
    pocx[i] = p[i].repx; pocy[i] = p[i].repy;
    maxy[p[i].repx] = max(maxy[p[i].repx], p[i].repy);
    maxx[p[i].repy] = max(maxx[p[i].repy], p[i].repx);
    p[i].ind = i;
  }

  sort(p, p + n);
  memset(l, -1, sizeof l);

  for (int i=0; i<n; i++) {
    if (i && p[i-1].repx == p[i].repx && p[i-1].repy == p[i].repy)
      continue;
    for (; (int) V.size() > 1; ) {
      int tmp = Ccw(V[V.size()-2], V.back(), p[i]);
      if (tmp == -1)
        V.pop_back();
      else if (tmp == 0) {
        l[V.back().ind] = V[V.size()-2].ind;
        r[V.back().ind] = p[i].ind;
        V.pop_back();
      }
      else
        break;
    }

    V.push_back(p[i]);
  }

  for (int i=0; i<(int) V.size(); i++) {
    if (i && V[i].repx <= V[i-1].repx && V[i].repy <= V[i-1].repy)
      break;
    if (maxx[V[i].repy] == V[i].repx && maxy[V[i].repx] == V[i].repy)
      rje[V[i].ind] = 1;
  }

  for (int i=n-1; i>=0; i--) {
    int ind = p[i].ind;
    if (!rje[ind] && l[ind] != -1 && rje[l[ind]] && rje[r[ind]]
        && maxx[p[ind].repy] == p[ind].repx && maxy[p[ind].repx] == p[ind].repy)
      rje[ind] = 1;
  }

  for (int i=0; i<n; i++)
    if (rje[i])
      M[make_pair(pocx[i], pocy[i])] = 1;

  for (int i=0; i<n; i++)
    if (rje[i] || M[make_pair(pocx[i], pocy[i])])
      printf("%d ", i + 1);
  printf("\n");

  return 0;
}