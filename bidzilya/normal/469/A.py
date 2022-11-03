n = int(raw_input())
a = map(int, raw_input().split(' '))
b = map(int, raw_input().split(' '))

a = a[1:]
b = b[1:]

good = True
for i in xrange(n):
    good = good and (((i + 1) in a) or ((i + 1) in b))

if good:
    print 'I become the guy.'
else:
    print 'Oh, my keyboard!'