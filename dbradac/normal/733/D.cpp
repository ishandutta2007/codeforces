#include <cstdio>
#include <map>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=a; i<b; i++)

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

int p[MAX][3];
vector <int> Rje;
map <P, P> M;

int main()
{
  int mx = -1;
  int n;

  scanf("%d", &n);

  REP(i, n)
    REP(j, 3)
      scanf("%d", &p[i][j]);

  REP(i, n) {
    sort(p[i], p[i] + 3);

    if (p[i][0] > mx) {
      mx = p[i][0];
      Rje = vector<int>{i};
    }

    do {
      P ja = P(p[i][0], p[i][1]);
      if (mx < min(p[i][2] + M[ja].X, min(p[i][0], p[i][1]))) {
        mx = min(p[i][2] + M[ja].X, min(p[i][0], p[i][1]));
        Rje = vector<int>{M[ja].Y, i};
      }
            
    } while(next_permutation(p[i], p[i] + 3));


    sort(p[i], p[i] + 3);

    do {
      P ja = P(p[i][0], p[i][1]);
      M[ja] = max(M[ja], P(p[i][2], i));
    } while(next_permutation(p[i], p[i] + 3));
  }
  
  printf("%d\n", (int) Rje.size());
  for (auto it : Rje)
    printf("%d ", it + 1);
  printf("\n");

  return 0;
}