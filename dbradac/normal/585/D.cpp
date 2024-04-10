#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 30, INF = 0x3f3f3f3f;

vector <pair<P, P> > V1, V2;
int p[3][MAX];

void Ispis(int len, int st)
{
  char isp[3][5] = { "LM", "LW", "MW" };

  for (int i=0; i<len; i++, st /= 3)
    printf("%s\n", isp[st % 3]);
}

void Rek(int a, int b, int c, int ind, int kraj, int st, int pot, vector <pair<P, P> > &V)
{
  if (ind == kraj) {
    V.push_back(make_pair(P(a - b, a - c), P(a, st)));
    return;
  }

  Rek(a + p[0][ind], b + p[1][ind], c, ind + 1, kraj, st, pot * 3, V);
  Rek(a + p[0][ind], b, c + p[2][ind], ind + 1, kraj, st + pot, pot * 3, V);
  Rek(a, b + p[1][ind], c + p[2][ind], ind + 1, kraj, st + 2 * pot, pot * 3, V);
}

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++)
    for (int j=0; j<3; j++)
      scanf("%d", &p[j][i]);

  int sred = (n - 1) / 2;

  Rek(0, 0, 0, 0, sred + 1, 0, 1, V1);
  Rek(0, 0, 0, sred + 1, n, 0, 1, V2);

  sort(V2.begin(), V2.end());

  int rje = 0, da = 0;
  P st;

  for (int i=0; i<(int) V1.size(); i++) {
    pair<P, P> traz = make_pair(P(-V1[i].X.X, -V1[i].X.Y), P(INF, INF));
    vector <pair<P, P> > :: iterator it = upper_bound(V2.begin(), V2.end(), traz);
    if (it == V2.begin())
      continue;

    it--;
    if (it->X != P(-V1[i].X.X, -V1[i].X.Y))
      continue;

    if (!da || rje < it->Y.X + V1[i].Y.X) {
      da = 1;
      rje = it->Y.X + V1[i].Y.X;
      st = P(V1[i].Y.Y, it->Y.Y);
    }
  }

  if (!da)
    printf("Impossible\n");
  else {
    Ispis(sred + 1, st.X);
    Ispis(n - sred - 1, st.Y);
  }

  return 0;
}