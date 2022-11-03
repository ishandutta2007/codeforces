m, n = map(int, raw_input().split(' '))
a = map(int, raw_input().split(' '))

a.sort()

ans = 1000 ** 3

for i in xrange(n):
    if (i + m - 1 < n):
        ans = min(ans, a[i + m - 1] - a[i])

print ans