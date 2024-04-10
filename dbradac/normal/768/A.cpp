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

int p[1<<17];

int main()
{
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", &p[i]);
  sort(p, p + n);
  int rje = max(0, n - (upper_bound(p, p+n, p[0]) - p + 
			p + n - lower_bound(p, p+n, p[n-1])));

  printf("%d\n", rje);

  return 0;
}