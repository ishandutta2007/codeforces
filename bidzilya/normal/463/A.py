n, s = map(int, raw_input().split(' '))
s *= 100
ans = -1
for i in xrange(n):
    x, y = map(int, raw_input().split(' '))
    cs = s - (x * 100 + y)
    if cs < 0:
        continue
    cs %= 100
    ans = max(ans, cs)
print ans