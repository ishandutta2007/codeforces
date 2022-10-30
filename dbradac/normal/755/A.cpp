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

const int MAX = 1<<20;

int sito[MAX];

int main()
{
  FOR(i, 2, MAX) {
    if (!sito[i]) {
      for (int j=i+i; j<MAX; j+=i)
        sito[j] = 1;
    }
  }

  int n;
  scanf("%d", &n);

  FOR(i, 1, MAX) {
    if (sito[i*n+1]) {
      printf("%d\n", i);
      break;
    }
  }

  return 0;
}