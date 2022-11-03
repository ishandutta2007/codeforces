#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char str[100002];
vector<int> ans;

int main() {
  gets(str);
  int n = strlen(str), bal = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == '(') ++bal;
    else if (str[i] == ')') --bal;
    else ans.push_back(0);
  }
  for (int i = 0; i + 1 < ans.size(); ++i) {
    ans[i] = 1;
    bal--;
  }
  if (bal <= 0) {
    puts("-1");
    return 0;
  }
  ans.back() = bal;
  int p = 0; bal = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == '(') ++bal;
    if (str[i] == ')') --bal;
    if (str[i] == '#') {
      bal -= ans[p];
      ++p;
    }
    if (bal < 0) {
      puts("-1");
      return 0;
    }
  }
  for (int u : ans)
    printf("%d\n", u);
  return 0;
}