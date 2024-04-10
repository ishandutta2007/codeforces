#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

map <int, int> Mx, My;
map <P, int> M;

ll Pov2(int x)
{
  return (ll) x * (x - 1) / 2;
}

int main()
{
  int n;
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    Mx[x]++;
    My[y]++;
    M[P(x, y)]++;
  }

  ll rje=0;

  for (auto it : Mx)
    rje += Pov2(it.Y);

  for (auto it : My)
    rje += Pov2(it.Y);

  for (auto it : M)
    rje -= Pov2(it.Y);

  cout << rje << endl;

  return 0;
}