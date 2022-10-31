#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define X first
#define Y second
#define pb push_back
#define ll long long int
#define INF 0x3F3F3F3F
#define M_PI 3.14159265358979323846
#define EPS 1e-9

const int MAX = 22;

vector <int> V[1<<MAX];
bool bio[1<<(MAX+1)];
int p[1<<MAX];
int ima[1<<MAX];
int n, m, N, msk;

void dfs(int node) {
  if (bio[node]) return;
  bio[node] = 1;

  if (node < N) {
    REP(i, n)
      if (!((node>>i) & 1))
        dfs(node | (1<<i));

    if (ima[msk^node]) dfs(N + (msk^node));
  }
  else
    dfs(node - N);
}

int main(){
  scanf("%d%d", &n, &m); N = 1<<n;

  msk = N - 1;
  REP(i, m) {
    scanf("%d", &p[i]);
    ima[p[i]] = 1;
  }

  int sol = 0;
  REP(i, m) {
    if (!bio[N+p[i]]) {
      sol++;
      dfs(N+p[i]);
    }
  }

  printf("%d\n", sol);

  return 0;
}