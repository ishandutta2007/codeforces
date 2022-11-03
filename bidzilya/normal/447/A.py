def get_ints():
    return map(int, raw_input().strip().split(' '))

p, n = get_ints()

s = set()
ans = -1
for i in xrange(n):
    x = int(raw_input())
    x %= p
    if x in s:
        ans = i + 1
        break
    s.add(x)

print ans