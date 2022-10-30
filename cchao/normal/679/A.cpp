#include <cstdio>

bool vis[110] = {};
int cnt = 0;
char result[24];

void test(int x) {
  printf("%d\n", x);
  fflush(stdout);
  scanf("%s", result);
  if (result[0] == 'y')
    cnt++;
}

int main() {
  for (int i = 2; i <= 55; ++i) if (!vis[i]) {
    test(i);
    if (i <= 10)
      test(i * i);
    for (int j = i; j <= 55; j += i) {
      vis[j] = true;
    }
  }
  puts(cnt < 2 ? "prime" : "composite");
  return 0;
}