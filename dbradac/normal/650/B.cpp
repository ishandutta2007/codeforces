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

const int MAX = 500500;

char s[MAX];
int n, pom, rot, t;
ll pref[MAX];

ll Eval(int dokle, int suf)
{
  return pref[dokle] + (ll) pom * (2 * (dokle - 1) + n + 1 - suf) + pref[n] - pref[suf-1];
}

int main()
{
  scanf("%d%d%d%d%s", &n, &pom, &rot, &t, s+1);

  int rje = 0;

  for (int st=0; st<2; st++) {
    for (int i=1; i<=n; i++) {
      int tmp = 1;
      if (s[i] == 'w')
        tmp += rot;

      pref[i] = pref[i-1] + tmp;
    }
    pref[n+1] = pref[n];

    int des = 1;
    for (int i=1; i<=n; i++) {
      if (pref[i] + pom * (i - 1) > t)
        break;
      for (; Eval(i, des) > t; des++);
      rje = max(rje, i + n + 1 - des);
    }

    reverse(s + 2, s + n + 1);
  }

  rje = min(rje, n);
  printf("%d\n", rje);

  return 0;
}