def get_ints():
    return map(int, raw_input().split(' '))

n = int(raw_input())
a = []
for i in xrange(n):
    a.append(raw_input())

good = True
for i in xrange(n):
    for j in xrange(n):
        c = 0
        for di, dj in zip([-1, 0, 0, 1], [0, -1, 1, 0]):
            ni = i + di
            nj = j + dj
            if ni >= 0 and ni < n and \
               nj >= 0 and nj < n:
                if a[ni][nj] == 'o':
                    c += 1
        if c % 2 == 1:
            good = False

if good:
    print 'YES'
else:
    print 'NO'