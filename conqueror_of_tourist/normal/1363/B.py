import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    s = input().strip()
    n = len(s)

    tot0 = 0
    tot1 = 0
    for c in s:
        if c == '0':
            tot0 += 1
        else:
            tot1 += 1
    
    best = min(tot0, tot1)


    cur0 = 0
    cur1 = 0
    for c in s:
        if c == '0':
            cur0 += 1
        else:
            cur1 += 1

        best = min((best, cur0 + (tot1 - cur1), cur1 + (tot0 - cur0)))

    print(best)