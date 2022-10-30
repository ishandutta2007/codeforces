#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> P;

char s[1005];

int main()
{
  scanf("%s", s);
  int n = (int) strlen(s);

  int zad = -1;
  REP(i, n) {
    if (s[i] < 'a' || s[i] > 'z') {
      printf("NO\n");
      return 0;
    }
    if (s[i] - 'a' > zad + 1) {
      printf("NO\n");
      return 0;
    }
    zad = max(zad, s[i] - 'a');
  }

  printf("YES\n");

  return 0;
}