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

const int MAX = 1<<20;

vector <int> V[MAX];
int sol[MAX];

int main()
{
  int n;
  scanf("%d", &n);
  
  REP(i, n) {
    int x;
    scanf("%d", &x);
    V[n-x].push_back(i);
  }

  int ok = 1;
  int indc=1;
  FOR(i, 1, MAX) {
    if (V[i].size() % i) ok = 0;
    REP(j, (int) V[i].size()) {
      sol[V[i][j]] = indc;
      if (j % i == i - 1) indc++;
    }
  }

  if (!ok) printf("Impossible\n");
  else {
    printf("Possible\n");
    REP(i, n) printf("%d ", sol[i]);
    printf("\n");
  }  

  return 0;
}