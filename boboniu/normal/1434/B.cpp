#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 323456

int n, t, answer[maxN];
char s[10];
array<int, 2> oper[maxN];
stack<int> stk;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i++) {
    scanf("%s", s);
    if (s[0] == '+') {
      oper[i] = {1, ++t};
      stk.push(t);
    } else {
      int r;
      scanf("%d", &r);
      oper[i] = {2, r};
      if (stk.empty()) {
        printf("NO\n");
        return 0;
      }
      answer[stk.top()] = r;
      stk.pop();
    }
  }
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 0; i < 2 * n; i++) {
    if (oper[i][0] == 1) {
      q.push(answer[oper[i][1]]);
    } else {
      if (q.top() != oper[i][1]) {
        printf("NO\n");
        return 0;
      }
      q.pop();
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++)
    printf("%d ", answer[i]);
  printf("\n");
}