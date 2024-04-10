#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;

const int MAX = 1<<18;

int dp[MAX];
vector <int> V[MAX];
int deg[MAX];

int main() {
  llint rje = 0;
  int n, m;

  scanf("%d%d", &n, &m);

  for (int i=0; i<m; i++) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    deg[a]++;
    deg[b]++;
    if (a > b)
      swap(a, b);
    V[b].push_back(a);
  }

  for (int i=0; i<n; i++) {
    dp[i] = 1;
    for (int j=0; j<(int) V[i].size(); j++)
      dp[i] = max(dp[i], dp[V[i][j]] + 1);
    rje = max(rje, (llint) dp[i] *  deg[i]);
  }

  printf("%lld\n", rje);

  return 0;
}