n = int(raw_input())
a = map(int, raw_input().split(' '))

a.sort()
ans = 0
for i in xrange(n):
    ans += (i + 1) * a[i]
    if i + 1 != n:
        ans += a[i]

print ans