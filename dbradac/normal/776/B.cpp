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

const int MAX = 1<<17;

int p[MAX];

int main()
{
  FOR(i, 2, MAX) {
    if (!p[i]) {
      for (int j=i+i; j<MAX; j+=i)
	p[j] = 1;
    }
  }

  int n;
  scanf("%d", &n);
  if (n <= 2) {
    printf("%d\n", 1);
    REP(i, n) printf("%d ", 1);
    printf("\n");
    return 0;
  }
  
  printf("%d\n", 2);
  FOR(i, 2, n+2)
    printf("%d ", 1 + p[i]);
  printf("\n");

  return 0;
}