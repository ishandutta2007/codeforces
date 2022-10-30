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

const int MAX = 1<<18;
const ll MIL = (3e9) + 20;

int p[MAX];
ll pref[MAX], suf[MAX];

ll Abs(ll x)
{
  if (x < 0)
    return -x;
  return x;
}

int main()
{
  int n, k;

  scanf("%d%d", &n, &k);

  for (int i=0; i<=n; i++)
    scanf("%d", &p[i]);

  pref[0] = 0;

  for (int i=0; i<=n; i++) {
    ll pros = pref[i] + p[i];

    if (pros & 1)
      pref[i+1] = -MIL;
    else
      pref[i+1] = pros / 2;

    if (pref[i] == -MIL)
      pref[i+1] = -MIL;
  }

  suf[n+1] = 0;
  for (int i=n; i>=0; i--) {
    ll val = 2 * (suf[i+1] + p[i+1]);
    if (Abs(val) > MIL)
      val = MIL;

    suf[i] = val;
  }

  int rje = 0;
  for (int i=0; i<=n; i++) {
    if (pref[i] != -MIL) {
      ll dod = pref[i] + suf[i];
      if (Abs(dod) <= k && (i != n || dod))
        rje++;
    }
  }

  printf("%d\n", rje);

  return 0;
}