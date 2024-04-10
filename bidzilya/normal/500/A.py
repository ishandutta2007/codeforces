n, t = map(int, raw_input().split(' '))
a = map(int, raw_input().split(' '))
d = [False] * n
d[0] = True
for i in xrange(0, n - 1):
    if (d[i] == True):
        d[i + a[i]] = True
if (d[t - 1]):
    print 'YES'
else:
    print 'NO'