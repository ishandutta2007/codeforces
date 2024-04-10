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

const int MAX = 200100;

int n, treb;
int val[MAX];
vector <int> V[MAX];
vector <int> SumL[MAX], SumR[MAX];
vector <int> MaxL[MAX], MaxR[MAX];
vector <int> KrivL[MAX], KrivR[MAX];
int pozl[MAX], pozr[MAX];
int dpdown[MAX], dpup[MAX], bio[MAX];
int krivdown[MAX], krivup[MAX];
int maxup[MAX], sumup[MAX];
int x;

void DfsDown(int node, int par)
{
  bio[node] = 1;

  int kriv = 0;
  SumL[node].push_back(0);
  MaxL[node].push_back(0);
  KrivL[node].push_back(0);

  for (auto ch : V[node]) {
    if (ch != par) {
      pozl[ch] = (int) SumL[node].size() - 1;

      if (val[ch] >= x)
        DfsDown(ch, node);

      int nsum = SumL[node].back(), nmax = MaxL[node].back();

      if (!krivdown[ch])
        nsum += dpdown[ch];
      else {
        nmax = max(nmax, dpdown[ch]);
        kriv = 1;
      }

      SumL[node].push_back(nsum);
      MaxL[node].push_back(nmax);
      KrivL[node].push_back(kriv);
    }
  }

  krivdown[node] = kriv;

  SumR[node].push_back(0);
  MaxR[node].push_back(0);
  KrivR[node].push_back(0);
  kriv = 0;

  for (int i=(int) V[node].size()-1; i>=0; i--) {
    int ch = V[node][i];
    if (ch != par) {
      pozr[ch] = (int) SumR[node].size() - 1;

      int nsum = SumR[node].back(), nmax = MaxR[node].back();

      if (!krivdown[ch])
        nsum += dpdown[ch];
      else {
        nmax = max(nmax, dpdown[ch]);      
        kriv = 1;
      }

      SumR[node].push_back(nsum);
      MaxR[node].push_back(nmax);
      KrivR[node].push_back(kriv);
    }
  }

  krivdown[node] = kriv;
  dpdown[node] = 1 + SumL[node].back() + MaxL[node].back();
}

int DfsUp(int node, int par)
{
  bio[node] = 1;

  if (par == -1) {    
    maxup[node] = 0;
    sumup[node] = 0;
    dpup[node] = 0;
    if (dpdown[node] >= treb)
      return 1;
  }
  else {
    if (krivup[par])
      maxup[node] = max(maxup[node], dpup[par]);
    else
      sumup[node] += dpup[par];

    maxup[node] = max(maxup[node], MaxL[par][pozl[node]]);
    sumup[node] += SumL[par][pozl[node]];

    maxup[node] = max(maxup[node], MaxR[par][pozr[node]]);
    sumup[node] += SumR[par][pozr[node]];

    krivup[node] = krivup[par] | KrivL[par][pozl[node]] | KrivR[par][pozr[node]];

    dpup[node] = maxup[node] + sumup[node] + 1;

    int tmax = MaxL[node].back(), tsum = SumL[node].back();
    if (krivup[node])
      tmax = max(tmax, dpup[node]);
    else
      tsum += dpup[node];

    if (1 + tmax + tsum >= treb)
      return 1;
  }

  for (auto ch : V[node])
    if (val[ch] >= x && ch != par)
      if (DfsUp(ch, node))
        return 1;

  return 0;
}

int Moze()
{
  memset(krivdown, 0, sizeof krivdown);
  memset(krivup, 0, sizeof krivup);
  memset(dpdown, 0, sizeof dpdown);
  memset(dpup, 0, sizeof dpup);
  memset(maxup, 0, sizeof maxup);
  memset(sumup, 0, sizeof sumup);
  for (int i=0; i<n; i++) {
    SumL[i].clear();
    SumR[i].clear();
    MaxL[i].clear();
    MaxR[i].clear();
    KrivL[i].clear();
    KrivR[i].clear();
  }

  for (int i=0; i<n; i++)
    if (val[i] < x) {
      krivdown[i] = krivup[i] = 1;
    }

  memset(bio, 0, sizeof bio);
  for (int i=0; i<n; i++)
    if (!bio[i] && val[i] >= x)
      DfsDown(i, -1);

  memset(bio, 0, sizeof bio);

  for (int i=0; i<n; i++)
    if (!bio[i] && val[i] >= x)
      if (DfsUp(i, -1))
        return 1;

  return 0;
}

int main()
{
  scanf("%d%d", &n, &treb);

  for (int i=0; i<n; i++)
    scanf("%d", &val[i]);

  for (int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  int lo = 0, hi = 1<<20;

  for (; lo<hi; ) {
    x = (lo + hi + 1) / 2;
    if (Moze())
      lo = x;
    else
      hi = x - 1;
  }

  printf("%d\n", lo);

  return 0;
}