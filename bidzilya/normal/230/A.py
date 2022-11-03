s, n = map(int, raw_input().split(' '))

a = []

for i in xrange(n):
    a.append(map(int, raw_input().split(' ')))

a.sort()

good = True
for i in xrange(n):
    if a[i][0] >= s:
        good = False
    else:
        s += a[i][1]

if good:
    print 'YES'
else:
    print 'NO'