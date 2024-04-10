#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0;
  for(c = getchar();c < '0' || c > '9';c = getchar());
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res;
}

int main(){
  int a = getint(), b = getint(), c = getint(), d = getint();
  printf("%d\n",(max(a,c) + (b + d)) * 2 + 4);
  return 0;
}