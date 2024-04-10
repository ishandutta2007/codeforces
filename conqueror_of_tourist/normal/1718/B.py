import sys, random
input = sys.stdin.readline

from heapq import heappush, heappop

out = []
t = int(input())
for _ in range(t):
    k = int(input())
    a = list(map(int, input().split()))
    ta = sum(a)

    sf = 1
    fib = [0, 1]
    while sf < ta:
        fib.append(fib[-1] + fib[-2])
        sf += fib[-1]

    if sf > ta:
        out.append('NO')
        continue

    assert sf == ta

    if sf == 1:
        out.append('YES')
        continue

    fib.append(fib[-1] + fib[-2])
    fib = fib[2:]
    
    u = len(fib)
    ct = [0] * u
    bust = [0] * u

    bad = False
    
    for v in a:
        for i in range(u - 1, -1, -1):
            if v >= fib[i]:
                v -= fib[i]
                ct[i] += 1

                if v == 0:
                    bust[i] = True
        if v:
            bad = True

    want = [1] * u
    want[0] = 2
    want[-1] = 0

    for i in range(u - 1, 0, -1):
        if ct[i] != want[i]:
            if ct[i] == want[i] + 1 and i % 2 == 0 and bust[i]:
                ct[0] += 1
                for j in range(1, i, 2):
                    ct[j] += 1
                ct[i] -= 1
            else:
                bad = True

    for i in range(u):
        if ct[i] != want[i]:
            bad = True
        
    if bad:
        out.append('NO')
    else:
        out.append('YES')
        
print('\n'.join(out))