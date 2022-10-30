#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<19, LOG = 19;

int n;
char s[MAX];
int srank[LOG][2*MAX];
int tr;
int sufar[MAX], pozar[MAX];
int lcp[MAX];
int pref[MAX];
vector <int> V[2*MAX];

bool Manji(const int &a, const int &b)
{
  if (srank[tr][a] != srank[tr][b])
    return srank[tr][a] < srank[tr][b];
  return srank[tr][a+(1<<tr)] < srank[tr][b+(1<<tr)];
}

void GenArray()
{
  for (int i=0; i<n; i++)
    srank[0][i] = (int) s[i];

  int p[MAX];
  for (int i=0; i<n; i++)
    p[i] = i;

  for (int j=1; j<LOG; j++) {
    tr = j - 1;
    sort(p, p + n, Manji);

    int br = 1;
    srank[j][p[0]] = 1;

    for (int i=1; i<n; i++) {
      if (Manji(p[i-1], p[i]))
        br++;
      srank[j][p[i]] = br;
    }
  }

  memcpy(sufar, p, sizeof sufar);
  for (int i=0; i<n; i++)
    pozar[sufar[i]] = i;
  pozar[n] = n;
}

void GenLcp()
{
  int lc=0;
  for (int i=0; i<n; i++, lc = max(0, lc - 1)) {
    if (pozar[i] == n - 1)
      lc = 0;
    else
      for (; s[i+lc] == s[sufar[pozar[i]+1]+lc]; lc++);
    lcp[pozar[i]] = lc;
  }
}

void GenPref()
{
  int sum = 0;
  for (int i=0; i<n; i++) {
    if (s[i] == '(')
      sum++;
    else
      sum--;

    pref[i] = sum;
  }
}

int main()
{
  scanf("%d%s", &n, s);

  GenArray();
  GenLcp();
  GenPref();

  ll rje = 0;

  for (int i=n-1; i>=0; i--) {
    int poc = i;
    if (pozar[i])
      poc += lcp[pozar[i] - 1];

    int ind = pref[i] + MAX - 1;

    V[ind + 2].clear();
    if (s[i] == '(')
      rje += upper_bound(V[ind].begin(), V[ind].end(), poc, greater<int>()) - V[ind].begin();

    V[ind + 1].push_back(i);
  }

  printf("%lld\n", rje);

  return 0;
}