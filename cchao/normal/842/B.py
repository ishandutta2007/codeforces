ri = lambda: map(int, raw_input().split())
r, d = ri()
d = r - d
n = ri()[0]
ans = 0
for i in xrange(n):
    x, y, z = ri()
    sq = x ** 2 + y ** 2
    if d+z<=r-z and (d + z) ** 2 <= sq <= (r - z) ** 2:
        ans += 1

print ans