#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int dp[201][201][201];

void go(int r, int g, int b) {
  if (dp[r][g][b] != -1) return;
  dp[r][g][b] = 1;
  if (r > 1) go(r - 1, g, b);
  if (g > 1) go(r, g - 1, b);
  if (b > 1) go(r, g, b - 1);
  if (r > 0 && g > 0) go(r - 1, g - 1, b + 1);
  if (r > 0 && b > 0) go(r - 1, g + 1, b - 1);
  if (g > 0 && b > 0) go(r + 1, g - 1, b - 1); 
}

int main() {
  int n;
  scanf("%d", &n);
  string s;
  cin >> s;
  int cnt[256] = {0};
  for (char c : s) {
    cnt[c]++;
  }

  memset(dp, -1, sizeof(dp));
  go(cnt['R'], cnt['G'], cnt['B']);

  if (dp[0][0][1] != -1) cout << 'B';
  if (dp[0][1][0] != -1) cout << 'G';
  if (dp[1][0][0] != -1) cout << 'R';
  cout << endl;

  return 0;
}