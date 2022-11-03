def get_ints():
    return map(int, raw_input().strip().split(' '))

n = int(raw_input())

a = []
for i in xrange(n):
    a.append(get_ints())

a.sort()

last = 0
for i in xrange(n):
    if last > a[i][1]:
        last = a[i][0]
    else:
        last = a[i][1]

print last