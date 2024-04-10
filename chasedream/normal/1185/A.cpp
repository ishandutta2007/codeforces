#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  if (a > b) swap(a, b);
  if (b > c) swap(b, c);
  if (a > b) swap(a, b);
  printf("%d\n", max(0, d - (b - a)) + max(0, d - (c - b)));
  return 0;
}