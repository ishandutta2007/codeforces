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

string ss = "Bulbasaur";
int p[2000];
char s[1<<17];

int main()
{
  scanf("%s", s);
  int n = (int )strlen(s);

  REP(i, n)
    p[(int) s[i]]++;

  int rje = 1<<17;
  REP(i, (int) ss.size()) {
    int kol = 0;
    REP(j, (int) ss.size())
      kol += ss[i] == ss[j];

    rje = min(rje,p[(int) ss[i]] / kol);
  }

  printf("%d\n", rje);

  return 0;
}