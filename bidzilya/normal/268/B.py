n = int(raw_input())

if (n == 1):
    print 1
else:
    ans = n
    for i in xrange(0, n):
        ans += (n - i - 1) * (i + 1)
    print ans