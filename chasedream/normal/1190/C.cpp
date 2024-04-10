#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
char s[N];
int l[N], r[N];
int n, k;

void pre() {
  l[1] = 1, r[n] = n;
  for (int i = 2; i <= n; i++) {
    l[i] = (s[i] == s[i - 1] ? l[i - 1] : i);
  }
  for (int i = n - 1; i >= 1; i--) {
    r[i] = (s[i] == s[i + 1] ? r[i + 1] : i);
  }
}

bool check1() {
  if (n == k || l[n - k] == 1 || r[k + 1] == n) return 1;
  for (int i = 2; i <= n - k; i++) {
    if (s[i - 1] == s[i + k] && l[i - 1] == 1 && r[i + k] == n)
      return 1;
  }
  return 0;
}

bool check2() {
  if (2 * k < n) return 0;
  for (int i = 2; i <= n - k; i++) {
    if (l[i - 1] != 1 || r[i + k] != n) return 0;
  }
  return 1;
}

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  pre();
  if (check1()) {
    puts("tokitsukaze"); exit(0);
  }
  if (check2()) {
    puts("quailty"); exit(0);
  }
  puts("once again");
  return 0;
}