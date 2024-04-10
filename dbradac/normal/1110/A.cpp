#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int main()
{
  int b, k;
  int t = 1;

  int sol = 0;
  scanf("%d%d", &b, &k);

  vector <int> R;

  REP(i, k) {
    int x;
        scanf("%d", &x);
	R.push_back(x);
  }
  
  reverse(R.begin(), R.end());

  for (auto x : R) {
    sol = (int) ((sol + (ll) t * x) % 2);
    t = (t*b) % 2;
  }

  if (sol)
    printf("odd\n");
  else
    printf("even\n");

  return 0;
}