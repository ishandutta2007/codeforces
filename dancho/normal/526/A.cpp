#include <cstdio>
#include <cstring>

int n;
char s[256];
int ok[256][256];

int main() {

  scanf("%d", &n);
  scanf("%s", s);

  memset(ok, 0, sizeof(ok));
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') {
      continue;
    }
    for (int j = 0; j < i; ++j) {
      if (s[j] == '.') {
        continue;
      }
      ok[i][i - j] = 1 + ok[j][i - j];
      if (ok[i][i - j] >= 4) {
        printf("yes\n");
        return 0;
      }
    }
  }
  printf("no\n");
  return 0;
}