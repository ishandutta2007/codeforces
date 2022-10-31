#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> ans(n);
  vector<int> sumCnt(2 * n + 1, 0);
  int remain = m;
  
  int j;  
  for(j = 0; j < n; ++j) {    
    if (remain <= sumCnt[j + 1])
      break;
    remain -= sumCnt[j + 1];
    ans[j] = j+1;
    for(int i = 0; i < j; ++i)
      ++sumCnt[ans[i] + ans[j]];
  }

  if (j == n) {
    puts("-1");
    return 0;
  }
  
  int x = j+1;
  while (remain != sumCnt[x])
    ++x;
  ans[j] = x;

  int maxSum = (j == 0) ? ans[j] : (ans[j-1] + ans[j]);
  int cur = maxSum + 1;
  for(int i = j+1; i < n; ++i) {
    ans[i] = cur;
    cur += 2 * (maxSum + 1);
  }

  for(int i = 0; i < n; ++i)
    printf("%d ", ans[i]);
  puts("");

  return 0;
}