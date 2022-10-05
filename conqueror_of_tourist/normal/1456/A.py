import sys,io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
for _ in range(t):
    n, p, k = map(int, input().split())
    a = input()
    x, y = map(int, input().split())

    p -= 1

    out = [-1] * n
    for i in range(n - 1, -1, -1):
        if i + k >= n:
            out[i] = 0
        else:
            out[i] = out[i + k]

        if a[i] == 48:
            out[i] += x

    poss = []
    for i in range(n):
        if i < p:
            continue
        delete = i - p
        poss.append(delete * y + out[i])

    print(min(poss))