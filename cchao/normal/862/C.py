n, x = map(int, raw_input().split())

a = range(n)

if n % 2 == 1:
    for i in xrange(n - 1):
        a[i] ^= 2 ** 19
else:
    for i in xrange(n - 2):
        a[i] ^= 2 ** 19
        a[n - 2- i] ^= 2 ** 18

s = 0
for i in xrange(n - 1):
    s ^= a[i]

a[n - 1] = s ^ x

if len(a) != len(set(a)):
    print 'NO'
else:
    print 'YES'
    print (' '.join(map(str, a)))