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

const int MAX = 1<<17;

int p[MAX];

int main()
{
  int n;
  scanf("%d", &n);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    p[x]++;
  }

  int rje = 1;
  FOR(i, 2, MAX) {
    int tmp = 0;
    for (int j=i; j<MAX; j+=i)
      tmp += p[j];

    rje = max(rje, tmp);
  }

  printf("%d\n", rje);

  return 0;
}