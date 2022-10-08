import sys
from functools import reduce 

n,k = map(lambda x: int(x.strip()), sys.stdin.readline().split(' '))
a = list(map(lambda x: reduce(lambda x, y: (x << 8) + y, list(map(int, x.strip().split('.')))), sys.stdin.readlines()[:n]))

for x in range(32):
  if k == len(set(map(lambda t: t >> (31 - x), a))):
    s = ''
    x = ((1 << (x + 1)) - 1) << (31 - x)
    for i in range(4):
      s = str(x & 255) + '.' + s
      x >>= 8
    print(s[:-1])
    sys.exit(0)
print(-1)