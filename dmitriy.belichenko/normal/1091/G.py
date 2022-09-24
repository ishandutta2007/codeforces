import math
import random
n = int(input())
cur = []
cur.append(n)
for i in range(15):
    x = random.randint(1 , n - 1)
    print('sqrt', x * x % n)
    a = int(input())
    x += a
    p = []
    for u in cur:
        gc = math.gcd(u , x)
        p.append(gc)
        p.append(u // gc)
    cur = p
c = set()
for u in cur:
    if(u > 1):
        c.add(u)
print('!', len(c) , *c)