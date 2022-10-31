#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 1<<20;

P p[MAX];
vector <int> V[MAX];
int c[MAX];
int n, m;
int bio[MAX];
int taken[MAX];

void no() { printf("-1\n"); exit(0); }

int main()
{
  scanf("%d%d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  REP(i, n) {
    scanf("%d", &c[i]);
    p[i] = P(c[i], i);
  }
  sort(p, p+n);

  REP(iii, n) {
    int i = p[iii].Y;

    for (auto it : V[i]) {
      if (bio[it]) {
        taken[c[it]] = 1;
      }
    }

    FOR(j, 1, c[i]) if (!taken[j]) no();
    if (taken[c[i]]) no();

    bio[i] = 1;

    for (auto it : V[i]) {
      if (bio[it]) {
        taken[c[it]] = 0;
      }
    }
  }

  REP(i, n) printf("%d ", p[i].Y+1);
  printf("\n");

  return 0;
}