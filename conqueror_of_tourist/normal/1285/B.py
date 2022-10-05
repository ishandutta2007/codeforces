import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    input()
    l = list(map(int,input().split()))

    bad = False
    
    curr = 0
    for v in l:
        curr += v
        if curr <= 0:
            bad = True
            break

    l.reverse()
    curr = 0
    for v in l:
        curr += v
        if curr <= 0:
            bad = True
            break

    if bad:
        print('NO')
    else:
        print('YES')