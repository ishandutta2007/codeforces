#include <bits/stdc++.h>
using namespace std;
pair<int,int> ans[300001];
deque<int> lol;
int main() {
  int n,q,a,mx=0,cur = 0,st; long long query;
  scanf ("%d %d",&n,&q);
  for (int x = 0; x< n ; x++) {
    scanf ("%d",&a);
    lol.push_back(a);
    mx = max(mx,a);
  }
  while (1) {
    ans[++cur].first = lol.front(); lol.pop_front();
    ans[cur].second = lol.front(); lol.pop_front();
    if (ans[cur].first > ans[cur].second) lol.push_front(ans[cur].first), lol.push_back(ans[cur].second);
    else lol.push_back(ans[cur].first), lol.push_front(ans[cur].second);
    if (ans[cur].first == mx) {
      st = cur;
      break;
    }
  }
  lol.pop_front();
  while (!lol.empty()) ans[++cur] = {mx,lol.front()}, lol.pop_front();
  while (q--) {
    cin >> query;
    if (query <= cur) printf ("%d %d\n",ans[query].first,ans[query].second);
    else {
      query -= st;
      query %= (cur-st);
      printf ("%d %d\n",ans[st+query].first,ans[st+query].second);
    }
  }
  return 0;
}