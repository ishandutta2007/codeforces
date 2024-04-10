#include <cstdio>
#include <map>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 1<<26;

map<int, int> cnt;
char s[MAX];

int main()
{
  int n;
  scanf("%d", &n);

  ll sol=0;
  for (;n--;) {
    scanf( "%s", s);
    int msk=0;
    int l = (int) strlen(s);
    REP(j, l)
      msk ^= 1<<(s[j] -'a');

    sol += cnt[msk];
    REP(i, 26) {
      int nmsk = msk ^ (1<<i);
      sol += cnt[nmsk];
    }

    cnt[msk]++;
  }

  printf("%lld\n", sol);

  return 0;
}