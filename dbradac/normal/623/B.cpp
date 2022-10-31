#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<20, KOR = 32000;
const ll INF = 1e18;

int n;
int p[MAX];
int sito[KOR];
int bezp[MAX], sp[MAX];
int cijseg, cijprom;
vector <int> Pr;

void Eratosten()
{
  for (int i=2; i<KOR; i++) {
    if (!sito[i]) {
      Pr.push_back(i);
      for (int j=2*i; j<KOR; j+=i)
        sito[j] = i;
    }
  }
}

vector <int> Fak(int x)
{
  vector <int> R;

  for (int i=0; i<(int) Pr.size(); i++) {
    if (!(x % Pr[i]))
      R.push_back(Pr[i]);
    for (; !(x % Pr[i]); x /= Pr[i]);
  }

  if (x > 1)
    R.push_back(x);

  return R;
}

ll Rijesi(int x)
{
  memset(bezp, 0, sizeof bezp);
  memset(sp, 0, sizeof sp);

  int prvi = n, zadnji = 0;
  int ukprom = 0;

  for (int i=0; i<n; i++) {
    if (!(p[i] % x))
      bezp[i] = 1;
    if (!((p[i] + 1) % x) || !((p[i] - 1) % x))
      sp[i] = 1;

    if (!bezp[i] && !sp[i]) {
      prvi = min(prvi, i);
      zadnji = max(zadnji, i);
    }
    if (!bezp[i] && sp[i])
      ukprom++;
  }

  if (!ukprom && prvi == n)
    return 0;

  ll ret = INF;
  if (prvi == n)
    ret = (ll) cijprom * ukprom;

  ll maxx = -cijseg;
  int tprom = 0;

  for (int i=0; i<n; i++) {
    if (!bezp[i] && sp[i])
      tprom++;

    if (i >= zadnji)
      ret = min(ret, (ll) i * cijseg - maxx + ((ll) ukprom - tprom) * cijprom);

    if (i < prvi)
      maxx = max(maxx, (ll) -tprom * cijprom + (ll) i * cijseg);
  }

  return ret;
}

int main()
{
  Eratosten();

  scanf("%d%d%d", &n, &cijseg, &cijprom);

  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  ll rje = INF;

  vector <int> Bitni;

  for (int i=-1; i<=1; i++) {
    vector <int> T = Fak(p[0] + i);
    for (int j=0; j<(int) T.size(); j++)
      Bitni.push_back(T[j]);
  }

  for (int i=-1; i<=1; i++) {
    vector <int> T = Fak(p[n-1] + i);
    for (int j=0; j<(int) T.size(); j++)
      Bitni.push_back(T[j]);
  }

  sort(Bitni.begin(), Bitni.end());
  Bitni.resize(unique(Bitni.begin(), Bitni.end()) - Bitni.begin());

  for (int i=0; i<(int) Bitni.size(); i++)
    rje = min(rje, Rijesi(Bitni[i]));

  printf("%lld\n", rje);

  return 0;
}