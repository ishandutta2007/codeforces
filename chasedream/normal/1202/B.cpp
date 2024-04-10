%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 15;
char s[3000005];
int dis[15][15];
int n;
 
int solve(int x, int y) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      dis[i][j] = 1e9;
    }
  } 
  for (int i = 0; i < 10; i++) {
    dis[i][(i + x) % 10] = dis[i][(i + y) % 10] = 1;
  } 
  
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int x = dis[s[i - 1] & 15][s[i] & 15];
    if (x > 1000) {
      return -1;
    }
    ans += x - 1;
  }
  return ans;
} 
 
int main() {
  scanf("%s", s); n = strlen(s);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d ", solve(i, j));
    }
    putchar('\n');
  }
  return 0;
}
 //