t = int(input())
for _ in range(t):
    d, m = map(int, input().split())
    d += 1
    out = 1
    curr = 2
    while curr < d:
        out *= (curr // 2) + 1
        out %= m
        curr *= 2
    out *= (d - curr // 2 + 1)
    print((out - 1) % m)