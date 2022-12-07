#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 555555

int T;
int cnt[maxN], ans[maxN];
vector<int> pos[maxN];

bool solve() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n + 1; i++) {
    cnt[i] = 0;
    pos[i].clear();
  }
  for (int i = 0; i < n; i++) {
    int col;
    scanf("%d", &col);
    cnt[col]++;
    pos[col].push_back(i);
    ans[i] = -1;
  }
  priority_queue<array<int, 2>> heap;
  int trash = -1;
  for (int i = 1; i <= n + 1; i++) {
    if (cnt[i] == 0)
      trash = i;
    heap.push({cnt[i], i});
  }
  for (int i = 0; i < x; i++) {
    int col = heap.top()[1];
    heap.pop();
    ans[pos[col].back()] = col;
    //printf("place same %d %d\n", pos[col].back(), col);
    pos[col].pop_back();
    cnt[col]--;
    heap.push({cnt[col], col});
  }

  int remained = n - x, same = y - x;
  while (heap.top()[0] * 2 > remained) {
    int col = heap.top()[1];
    heap.pop();
    ans[pos[col].back()] = trash;
    //printf("place trash %d %d\n", pos[col].back(), trash);
    pos[col].pop_back();
    cnt[col]--;
    heap.push({cnt[col], col});
    remained--;
  }
  if (same > remained) {
    printf("NO\n");
    return false;
  }
  vector<int> remained_col;
  vector<int> remained_pos;
  int m = heap.top()[0];
  while (!heap.empty()) {
    int col = heap.top()[1];
    heap.pop();
    while (!pos[col].empty()) {
      remained_col.push_back(col);
      remained_pos.push_back(pos[col].back());
      pos[col].pop_back();
    }
  }
  assert(remained_col.size() == remained);
  for (int i = 0; i < remained; i++) {
    if (i >= same)
      ans[remained_pos[i]] = trash;
    else
      ans[remained_pos[i]] = remained_col[(i + m) % remained];
  }
  printf("YES\n");
  for (int i = 0; i < n; i++)
    printf("%d ", ans[i]);
  printf("\n");
  return true;
}

int main() {
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    solve();
  }
}