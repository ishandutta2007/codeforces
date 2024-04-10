#include <cstdio>
#include <map>
#include <string>
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

const int MAX = 1005;

map <string, int> M;
char s[MAX];

int main()
{
  int a, b, ab=0;

  scanf("%d%d", &a, &b);

  REP(i, a) {
    scanf(" %s", s);
    string ss = s;
    M[ss] = 1;
  }

  REP(i, b) {
    scanf(" %s", s);
    string ss = s;
    if (M[ss]) ab++;
  }

  a -= ab;
  b -= ab;

  for (;;) {
    if (ab) ab--;
    else {
      if (!a) {
        printf("NO\n");
        return 0;
      }
      a--;
    }

    if (ab) ab--;
    else {
      if (!b) {
        printf("YES\n");
        return 0;
      }
      b--;
    }
  }

  return 0;
}