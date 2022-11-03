def get_ints():
    return map(int, raw_input().split(' '))

n, c = get_ints()
a = get_ints()

ans = 0
for i in xrange(n - 1):
    val = a[i] - c - a[i + 1]
    if val > ans:
        ans = val
        f = True

print ans