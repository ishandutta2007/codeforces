#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

struct str {
  int n;
  vector <int> V;
};

bool operator < (const str &a, const str &b)
{
  if (a.n != b.n) return a.n < b.n;
  return a.V < b.V;
}

map <str, int> Sg;

int rek(str stanje)
{
  if (Sg.find(stanje) != Sg.end()) return Sg[stanje];
  
  int polje[70];
  memset(polje, 0, sizeof polje);

  FOR(i, 1, stanje.n+1) {
    auto it = lower_bound(stanje.V.begin(), stanje.V.end(), i);
    if (it != stanje.V.end() && *it == i) continue;
    vector <int> T = stanje.V;
    T.push_back(i);
    sort(T.begin(), T.end());
    int nval = stanje.n - i;
    for (; !T.empty() && T.back() > nval; T.pop_back());

    int tmp = rek({nval, T});
    polje[tmp] = 1;
  }

  for (int i=0; ; i++)
    if (!polje[i]) return Sg[stanje] = i;
}

int vr[100];

int main()
{
  FOR(i, 1, 62)
    vr[i] = rek({i, vector<int>()});
  
  int n;
  scanf("%d", &n);
  
  int val = 0;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    val ^= vr[x];
  }

  printf("%s\n", val ? "NO" : "YES");
  
  return 0;
}