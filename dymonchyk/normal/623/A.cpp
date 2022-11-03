#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char s[505];
bool f[505][505];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    f[a][b] = f[b][a] = true;
  }

  for (int i = 0; i < n; ++i) {
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (!f[i][j]) {
        ok = false;
        break;
      }
    }
    if (ok) s[i] = 'b';
  }

  bool first = true;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'b') continue;

    if (first) {
      s[i] = 'c';
      first = false;
      continue;
    }

    bool hasC = false;
    for (int j = 0; j < n; ++j) {
      if (s[j] == 'c' && f[i][j]) hasC = true;
    }
    s[i] = hasC ? 'c' : 'a';
  } 

  int who[3][3] = {{1, 1, 0},
                   {1, 1, 1},
                   {0, 1, 1}};

  bool ok = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      
      if (f[i][j] != who[s[i] - 'a'][s[j] - 'a'])
        ok = false;
    }
  }

  if (ok) {
    puts("Yes");
    puts(s);
  } else {
    puts("No");
  }

  return 0;
}