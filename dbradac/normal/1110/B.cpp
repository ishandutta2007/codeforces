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

const int MAX = 1<<17;

int p[MAX];
vector <int> R;

int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  REP(i, n) {
    scanf("%d", &p[i]);
  }
  sort(p, p+n);

  REP(i, n-1)
    R.push_back(p[i+1] - p[i]-1);

  sort(R.begin(), R.end(), greater<int>());

  ll sol = n;
  FOR(i, k-1, (int) R.size()) {
    //    TRACE(i _ R[i]);
    sol += R[i];
  }

  printf("%lld\n", sol);
  
  return 0;
}