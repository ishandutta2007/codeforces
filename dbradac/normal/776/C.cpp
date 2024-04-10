#include <map>
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
const ll MAXVAL = 1e16;

map <ll, int> M;
int p[MAX];

int main()
{
  int n;
  ll k;

  scanf("%d%lld", &n, &k);  
  ll rje = 0;
  ll sum = 0;
  
  M[0]++;

  REP(i, n) {
    scanf("%d", &p[i]);
    sum += p[i];
    
    for (ll pot = 1; pot < MAXVAL; pot *= k) {     
      rje += M[sum - pot];
      if (k == 1) break;
      if (k == -1 && pot == -1) break;
    }

    M[sum]++;
  }
  
  printf("%lld\n", rje);

  return 0;
}