def get_ints():
    return map(int, raw_input().strip().split(' '))

n, m = get_ints()
a = get_ints()

ans = 1
rem = m
for i in xrange(n):
    if rem < a[i]:
        rem = m
        ans += 1
    rem -= a[i]
print ans