def get_ints():
    return map(int, raw_input().split(' '))

n = int(raw_input())

a = []

for i in xrange(n):
    a.append(get_ints())

a.sort()

m = 0
found = False
for i in xrange(n):
    if a[i][1] < m:
        found = True

    m = max(m, a[i][1])

if found:
    print 'Happy Alex'
else:
    print 'Poor Alex'