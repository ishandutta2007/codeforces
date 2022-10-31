%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int dx[] = {0, -1, -1, 1, 1};
const int dy[] = {0, -1, 1, -1, 1};

char read_char() {
  for (;;) {
    char op = getchar();
    if (op == '.' || op == 'X') return op;
  }
}

char a[505][505];
int n;
int cnt = 0;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = read_char();
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int ok = 1;
      for (int k = 0; k < 5; k++) {
        int ii = i + dx[k], jj = j + dy[k];
        if (a[ii][jj] != 'X') ok = 0;
      }
      if (ok) cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}

//