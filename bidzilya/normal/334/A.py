n = int(raw_input())

a = []
for i in xrange(n):
    a.append([])

val = 1
while val <= (n ** 2):
    for i in xrange(n):
        a[i].append(val)
        val += 1
    for i in xrange(n):
        a[n - i - 1].append(val)
        val += 1

for i in xrange(n):
    for j in a[i]:
        print j,
    print