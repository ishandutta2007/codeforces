import sys
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    if n % 2 == 1:
        out.append('NO')
        continue
    l.sort()

    small = l[:(n//2)]
    big = l[(n//2):]
    
    res = [-1] * n

    for i in range(n//2):
        res[2 * i] = small[i]
        res[2 * i + 1] = big[i]


    bad = False
    for i in range(1, n, 2):
        if res[i] == res[i - 1] or res[i] == res[(i + 1) % n]:
            bad = True

    if bad:
        out.append('NO')
    else:
        out.append('YES')
        out.append(' '.join(map(str, res)))
print('\n'.join(map(str, out)))