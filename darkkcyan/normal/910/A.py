from __future__ import print_function, division
from collections import deque
import sys

n, d = map(int, raw_input().split())
s = raw_input()

dp = [-1 for i in xrange(n)]
qu = deque()

dp[0] = 0
qu.append(0)

for i in xrange(1, n):
    while len(qu) and qu[0] < i - d:
        qu.popleft()
    if s[i] == '0':
        continue
    if len(qu) == 0:
        print(-1)
        sys.exit(0)
    dp[i] = dp[qu[0]] + 1
    while len(qu) and dp[qu[-1]] > dp[i]:
        qu.pop()
    qu.append(i)

print(dp[-1])