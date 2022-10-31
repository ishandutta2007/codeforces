#include <queue>
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

const int MAX = 4100;

int nj;
int p[MAX];
int __bio[MAX];
int *bio = &__bio[MAX/2];

int main()
{
  int k;
  scanf("%d%d", &nj, &k);

  REP(i, k) {
    int x;
    scanf("%d", &x);
    p[x] = 1;
  }
  
  queue <int> Q;
  memset(__bio, -1, sizeof __bio);
  Q.push(0);

  for (; !Q.empty(); ) {
    int tmp = Q.front(); Q.pop();
    REP(i, 1005)
      if (p[i]) {
	int nov = tmp + i - nj;
	if (abs(nov) < 2005 && bio[nov] == -1) {
	  bio[nov] = max(0, bio[tmp]) + 1;
	  Q.push(nov);
	}
      }
  }
  
  printf("%d\n", bio[0]);

  return 0;
}