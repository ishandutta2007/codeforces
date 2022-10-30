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

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int M = 20000;

void nope()
{
  printf("NO\n");
  exit(0);
}

int main()
{
  int n, ver = M;

  scanf("%d", &n);

  REP(i, n) {
    int kol;
    scanf("%d ", &kol);
    string s;
    cin >> s;

    if (ver == M && s != "South") nope();
    if (ver == 0 && s != "North") nope();

    if (s == "South") {
      if (ver < kol)
        nope();
      ver -= kol;
    }
    if (s == "North") {
      if (ver + kol > M)
        nope();
      ver += kol;
    }
  }

  if (ver != M)
    nope();

  printf("YES\n");

  return 0;
}