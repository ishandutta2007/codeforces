from heapq import *

t = int(input())
for _ in range(t):
    aQ = [(0, -1)]
    bQ = [(0, -1)]

    n = int(input())

    good = ['0'] * n

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    
    for i in range(n):
        heappush(aQ, (-a[i], i))
        heappush(bQ, (-b[i], i))

    minA = a[bQ[0][1]]
    minB = b[aQ[0][1]]

    while True:
        if aQ[0][0] + minA <= 0:
            _, i = heappop(aQ)
            good[i] = '1'
            minB = min(minB, b[i])
        elif bQ[0][0] + minB <= 0:
            _, i = heappop(bQ)
            good[i] = '1'
            minA = min(minA, a[i])
        else:
            break

    print(''.join(good))