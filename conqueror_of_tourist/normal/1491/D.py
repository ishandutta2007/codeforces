import sys
input = sys.stdin.readline

def parse(x):
    out = []
    for i in range(29,-1,-1):
        if x >= (1 << i):
            out.append(i)
            x -= (1 << i)


    return out

res = []
n = int(input())
for _ in range(n):
    a, b = map(int, input().split())

    if a == b:
        res.append('YES')
        continue
    
    p1 = parse(a)
    p2 = parse(b)

    if len(p2) > len(p1):
        res.append('NO')
        continue

    start = 0
    while len(p2) > start and p1[start] == p2[start]:
        start += 1

    p1 = p1[start:]
    p2 = p2[start:]

    if len(p2) == 0 or p2[0] < p1[0]:
        res.append('NO')
        continue

    assert p2[0] > p1[0]

    for i in range(len(p2) - 1):
        if p1[-i-1] > p2[-i-1]:
            res.append('NO')
            break
    else:
        res.append('YES')
    
    

    

print('\n'.join(res))