t = int(input())
for _ in range(t):
    n,m = map(int, input().split())
    l = []
    for _ in range(n):
        l.append(list(map(int,input().split())))
    zeroes = [0] * (m + n - 1)
    ones = [0] * (m + n - 1)

    for i in range(n):
        for j in range(m):
            if l[i][j] == 0:
                zeroes[i + j] += 1
            else:
                ones[i + j] += 1

    out = 0

    for i in range((m + n - 1)//2):
        z = zeroes[i] + zeroes[m + n - 2 - i]
        o = ones[i] + ones[m + n - 2 - i]
        out += min(o,z)
    print(out)