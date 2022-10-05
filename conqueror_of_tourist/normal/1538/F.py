t = int(input())
for _ in range(t):
    out = 0
    l, r = map(int, input().split())
    while l + r > 0:
        out += r - l
        r //= 10
        l //= 10
    print(out)