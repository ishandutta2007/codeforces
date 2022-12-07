#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 423456

int n, a[maxN], cnt[maxN];
int s[maxN], pos[maxN], answer;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  int cntmode = 0;
  for (int i = 1; i <= n; i++)
    cntmode = max(cntmode, cnt[i]);
  vector<int> modes;
  for (int i = 1; i <= n; i++)
    if (cnt[i] == cntmode) {
      modes.push_back(i);
    }
  if (modes.size() >= 2) {
    printf("%d\n", n);
    return 0;
  }
  int M = modes[0];
  for (int m = 1; m <= 100; m++) {
    if (m == M)
      continue;
    for (int j = 1; j <= n; j++) {
      if (a[j] == M)
        s[j] = s[j - 1] + 1;
      else if (a[j] == m)
        s[j] = s[j - 1] - 1;
      else
        s[j] = s[j - 1];
    }
    for (int i = 0; i <= 2 * n + 1; i++)
      pos[i] = n + 1;
    for (int i = 0; i <= n; i++)
      pos[s[i] + n] = min(pos[s[i] + n], i);
    for (int i = 2 * n; i >= 0; i--)
      pos[i] = min(pos[i], pos[i + 1]);
    for (int i = 1; i <= n; i++) {
      answer = max(answer, i - pos[s[i] + n]);
    }
  }
  printf("%d\n", answer);
}