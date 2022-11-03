def get_ints():
    return map(int, raw_input().strip().split(' '))


n, m = get_ints()
a = get_ints()

for i in xrange(n):
    for j in xrange(m):
        if a[j] <= i + 1:
            print a[j],
            break