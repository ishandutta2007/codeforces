#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
using namespace std;

int in[105];
int cnt[105];
int tot[105];
int main() {
  int N, A, i, j;
  scanf("%d %d", &N, &A);
  for(i = 1; i <= N; i++) scanf("%d", &in[i]);

  for(i = 1; i <= N; i++) tot[abs(i-A)]++;
  for(i = 1; i <= N; i++) cnt[abs(i-A)] += in[i];

  int ans = 0;
  for(i = 0; i <= N; i++) if(tot[i] == cnt[i]) ans += cnt[i];
  return !printf("%d\n", ans);
}