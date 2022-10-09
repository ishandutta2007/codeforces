from sys import *
import math
def numline(f = int):
  return map(f, input().split())
    
n = int(input())
a = list(filter(lambda x: x != 0, numline(lambda s: int(s.split('.')[1]))))
# print(' '.join(map(str, a)))
c0 = min(2 * n - len(a), len(a))
s = sum(a) - 1000 * min(n, len(a))
ans = abs(s)
for i in range(c0):
  s += 1000
  ans = min(ans, abs(s))

print('{}.{:0>3}'.format(ans // 1000, ans % 1000))