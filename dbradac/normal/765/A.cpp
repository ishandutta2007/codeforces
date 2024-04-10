#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> P;

int main()
{
  int x;
  scanf("%d", &x);
  printf("%s\n", (x % 2) ? "contest" : "home");
  
  return 0;
}