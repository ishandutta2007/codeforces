#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int>> chosen;
priority_queue<int> choices;
int main() {
  int n,m,sum=0,sub = 0,a;
  scanf ("%d %d",&n,&m);
  for (int x = 0; x < n; x++) {
      scanf ("%d",&a);
      sum += a;
      while (sum - sub > m) {
        sub += choices.top();
        chosen.push(choices.top());
        choices.pop();
      }
      while (chosen.size() && sum - (sub - chosen.top()) <= m) {
        choices.push(chosen.top());
        sub -= chosen.top();
        chosen.pop();
      }
      printf ("%d%c",chosen.size(),x==n-1?'\n':' ');
      if (x != n-1 && chosen.size() && chosen.top() < a) {
        sub -= chosen.top();
        sub += a;
        choices.push(chosen.top());
        chosen.pop();
        chosen.push(a);
      }
      else {
        choices.push(a);
      }
  }
  return 0;
}
/*
5 10
4 9 1 10 5
*/