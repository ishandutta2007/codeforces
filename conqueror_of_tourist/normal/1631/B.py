import sys
input = sys.stdin.readline

from math import gcd

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    v = l[-1]
    
    ans = 0
    curr = n - 1
    while curr >= 0:
        if l[curr] == v:
            curr -= 1
        else:
            sz = n - curr - 1
            nsz = 2 * sz
            curr = n - 1 - nsz
            ans += 1
    out.append(ans)
print('\n'.join(map(str,out)))