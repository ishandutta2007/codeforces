ri = lambda: map(int, raw_input().split())
a, b = ri()
c, d = ri()
dx = abs(a - c)
dy = abs(b - d)

ans = (dx + dy) * 2 + 4
if dx == 0 or dy == 0:
    ans += 2
print ans