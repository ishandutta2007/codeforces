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
vector <int> T;
int bio[MAX];

void dfs(int node)
{
  bio[node] = 1;
  T.push_back(node);
  
  for (auto it : V[node]) {
    if (bio[it]) continue;
    dfs(it);
    T.push_back(node);
  }
}

int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  dfs(0);

  int kol = (2*n - 1) / k + 1;

  int ind = 0;
  REP(i, k) {
    if (ind >= (int) T.size())
      printf("1 1\n");    
    else {
      vector <int> A;
      for (int j=0; j<kol && ind < (int) T.size(); j++, ind++)
	A.push_back(T[ind]);
      printf("%d ", (int) A.size());
      for (auto it : A)
	printf("%d ", it+1);
      printf("\n");
    }
  }
  

  return 0;
}