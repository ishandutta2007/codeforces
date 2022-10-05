from collections import defaultdict
from math import gcd
import sys
input = sys.stdin.readline
out = []
for _ in range(int(input())):
    n = int(input())
    dir = defaultdict(int)
    
    out.append(0)
    
    for _ in range(n):
        a, b, x, y = map(int, input().split())
        dx = x-a
        dy = y-b
        
        g = gcd(dx,dy)
        dx //= g
        dy //= g
        
        out[-1] += dir[(dx,dy)]
        dir[(-dx,-dy)] += 1
        
print('\n'.join(map(str,out)))