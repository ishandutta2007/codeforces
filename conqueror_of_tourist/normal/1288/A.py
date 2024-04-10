import math

t = int(input())
for _ in range(t):
    n, d = map(int, input().split())
    
    curr = 0
    currval = d

    while True:
        nex = math.ceil(d/(curr+2))
        if nex < currval:
            currval = nex
            curr += 1
        else:
            break
            
    if (curr + currval <= n):
        print('YES')
    else:
        print('NO')