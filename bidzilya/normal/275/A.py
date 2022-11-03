def get_ints():
    return map(int, raw_input().strip().split(' '))

a = []
for i in xrange(3):
    a.append(get_ints())

for i in xrange(3):
    s = ''
    for j in xrange(3):
        sm = a[i][j]
        for di, dj in zip([-1, 0, 0, 1], [0, -1, 1, 0]):
             ni = i + di
             nj = j + dj

             if ni >= 0 and ni < 3 and \
                nj >= 0 and nj < 3:
                 sm += a[ni][nj]
        sm %= 2
        sm = 1 - sm
        s += chr(ord('0') + sm)
    print s