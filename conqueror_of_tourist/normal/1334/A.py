import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    lastP = 0
    lastC = 0
    works = True
    for _ in range(n):
        p, c = map(int, input().split())
        pDiff = p-lastP
        cDiff = c-lastC
        if 0 <= cDiff <= pDiff:
            pass
        else:
            works = False
        lastP = p
        lastC = c
    if works:
        print('YES')
    else:
        print('NO')