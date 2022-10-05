INF = 10**6

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    out = [0] * (n + 1)

    for i in range(1, n + 1):
        best = INF
        if i >= 2:
            best = min(best, a[i-2] + out[i-2])
        if i >= 3:
            best = min(best, a[i-3] + out[i-3])
        if i >= 4:
            best = min(best, a[i-4] + a[i-3] + out[i-4])
        out[i] = best

    fin = out[n]
    for i in range(1,4):
        if i <= n:
            fin = min(fin, out[n-i] + a[n-i])
    print(fin)