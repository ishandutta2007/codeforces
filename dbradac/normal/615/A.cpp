#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;

const int MAX = 105;

int bio[MAX];

int main() {
  int n, m;

  scanf("%d%d", &n, &m);

  for (int i=0; i<n; i++) {
    int k;
    scanf("%d", &k);
    for (; k--; ) {
      int tmp;
      scanf("%d", &tmp);
      bio[tmp] = 1;
    }
  }

  int da=1;
  for (int i=1; i<=m; i++)
    if (!bio[i])
      da = 0;

  printf("%s\n", da ? "YES" : "NO");

  return 0;
}