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

int p[MAX], poz[MAX];
int bio[MAX];

int main()
{
  int n;
  scanf("%d", &n);
  vector <int> V;
  
  REP(i, n) {
    scanf("%d", &p[i]);
    V.push_back(p[i]);
  }

  sort(V.begin(), V.end());
  REP(i, n)
    p[i] = (int) (lower_bound(V.begin(), V.end(), p[i]) - V.begin());

  vector <vector<int> > R;
  
  REP(i, n) {
    if (bio[i]) continue;
    vector <int> T;
    for (int tmp=i; !bio[tmp]; tmp=p[tmp]) {
      T.push_back(tmp);
      bio[tmp] = 1;
    }
    R.push_back(T);
  }

  // REP(i, n) TRACE(i _ p[i]);

  printf("%d\n", (int) R.size());
  for (auto it : R) {
    printf("%d ", (int) it.size());
    sort(it.begin(), it.end());
    for (auto tmp : it)
      printf("%d ", tmp+1);
    printf("\n");
  }    

  return 0;
}