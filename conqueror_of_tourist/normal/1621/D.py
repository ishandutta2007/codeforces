import sys
input = sys.stdin.readline

out = []
t = int(input())
for _ in range(t):
    n = int(input())
    o = 0
    c = []
    
    for i in range(2 * n):
        c.append(list(map(int, input().split())))

    for i in range(n):
        for j in range(n):
            o += c[n+i][n+j]

    poss = []
    for i in [0, n - 1]:
        for j in [-1, -n]:
            poss.append(c[i][j])

    for j in [0, n - 1]:
        for i in [-1, -n]:
            poss.append(c[i][j])

    out.append(o + min(poss))
print('\n'.join(map(str,out)))