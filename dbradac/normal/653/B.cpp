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

const int MAX = 50;

map <int, ll> M[50];
string poc[MAX], kraj[MAX];

int main()
{
  int len, n;

  scanf("%d%d", &len, &n);

  for (int i=0; i<n; i++) {
    cin >> poc[i] >> kraj[i];
    M[2][i] = 1;
  }

  for (int i=2; i<len; i++)
    for (auto it : M[i])
      for (int j=0; j<n; j++)
        if (kraj[it.X][0] == poc[j][0])
          M[i+1][j] += it.Y;

  ll rje = 0;
  for (auto it : M[len])
    if (kraj[it.X] == "a")
      rje += it.Y;

  printf("%lld\n", rje);

  return 0;
}