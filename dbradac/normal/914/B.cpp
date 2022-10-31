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
  int n;
  scanf("%d", &n);

  REP(i, n) {
    int x;
    scanf("%d", &x);
    p[x]++;
  }

  int rj=1;
  REP(i, MAX)
    if (p[i] % 2) rj = 0;

  printf("%s\n", rj == 0 ? "Conan" : "Agasa");

  return 0;
}