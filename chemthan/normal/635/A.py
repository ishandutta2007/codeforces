r, c, n, k = map(int, input().split())
a = [[0 for i in range(0, c)] for j in range(0, r)]
for i in range(0, n):
    x, y = map(int, input().split())
    x = x - 1
    y = y - 1
    a[x][y] = 1
ans = 0
for i in range(0, r):
    for j in range(0, c):
        for u in range(i, r):
            for v in range(j, c):
                t = 0
                for x in range(i, u + 1):
                    for y in range(j, v + 1):
                        t += a[x][y]
                if t >= k:
                    ans = ans + 1
print(ans);