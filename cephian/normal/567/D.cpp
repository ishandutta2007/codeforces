#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int n,k,a,m;
set<int> block;

int acc(int len) {
  if(len < a) return 0;
  return 1 + (len-a)/(a+1);
}

int r(int x) {
  return *block.upper_bound(x);
}

int l(int x) {
  set<int>::iterator i = block.lower_bound(x);
  return *(--i);
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k >> a >> m;
  int mx = acc(n);
  block.insert(0);
  block.insert(n+1);
  for(int i = 1; i <= m; ++i) {
    int x;
    cin >> x;
    int lb = l(x);
    int rb = r(x);
    block.insert(x);
    mx += -acc(rb-lb-1) + acc(x-lb-1) + acc(rb-x-1);
    if(mx < k) {
      cout << i << "\n";
      return 0;
    }
  }

  cout << "-1\n";

  return 0;
}