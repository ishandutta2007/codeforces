// Copy

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // codeforces


#include <bits/stdc++.h>
using namespace std;

array<int, 12> value{};
array<uint32_t, (1<<12)> count{};
array<uint8_t, (1<<12)> wu{};

int n;
void f(int i, int val, int bits) {
  if (i == n) {
    // cout << bitset<2>(bits) << " " << bitset<2>(mask.to_ulong()) << " "  << val << '\n';
    wu[bits] = min(101, val);
    return;
  }
  f(i+1, val+value[i], bits<<1 | 0);
  f(i+1, val,          bits<<1 | 1);
}

int32_t read_bitstring(size_t len) {
  int32_t num=0;
  scanf(" ");
  while (len--) {
    char c=getchar();
    num = num<<1 | (c == '1' ? 1 : 0);
  }
  return num;
}

signed main() {
  int m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i=0; i<n; ++i)
    scanf("%d", &value[0]+i);
  for (int i=0; i<m; ++i) {
    ++::count[read_bitstring(n)];
  }
  f(0, 0, 0);
  while (q--) {
    uint32_t mask = read_bitstring(n);
    int w; scanf("%d", &w);
    int ans=0;
    for (uint32_t i=0; i<wu.size(); ++i)
        if(wu[i] <= w) ans += ::count[i^mask];
    printf("%d\n", ans); 
  }
}

/*
 * Local variables:
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g3 -ggdb3 -O0 -Wall -Wextra -std=c++14 d.cc -o d && for f in *.in; do echo \"--- $f -------------\"; ./d <$f; done"
 * end:
 */