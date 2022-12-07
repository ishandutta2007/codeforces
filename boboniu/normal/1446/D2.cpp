#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 423456

int n, a[maxN], cnt[maxN];
int s[maxN], pos[maxN], answer, val[maxN];
vector<int> npos[maxN];
int T = 300;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    npos[a[i]].push_back(i);
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
  for (int m = 1; m <= n; m++) {
    if (m == M)
      continue;
    if (cnt[m] <= T)
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
  npos[M].insert(npos[M].begin(), 0);
  npos[M].push_back(n + 1);
  for (int ocr = 0; ocr <= T + 1; ocr++) {
    for (int i = 0; i <= n; i++)
      val[i] = n + 1;
    for (int i = 1; i <= n; i++) {
      if (i == M)
        continue;
      for (int j = 0; j < npos[i].size(); j++) {
        if (j + ocr - 1 < (int)npos[i].size()) {
          val[npos[i][j]] = npos[i][max(j + ocr - 1, j)];
        }
      }
    }
    for (int i = 0; i <= n + 1; i++)
      pos[i] = -1;
    for (int i = 1; i <= n; i++)
      pos[val[i]] = max(pos[val[i]], i);
    for (int i = 1; i <= n; i++)
      pos[i] = max(pos[i], pos[i - 1]);
    for (int i = 0; i < npos[M].size(); i++) {
      if (i + ocr + 1 >= npos[M].size())
        break;
      int Rl = npos[M][i] + 1, Rr = npos[M][i + ocr + 1] - 1;
      if (pos[Rr] >= Rl) {
        answer = max(answer, Rr - Rl + 1);
      }
    }
  }
  printf("%d\n", answer);
}