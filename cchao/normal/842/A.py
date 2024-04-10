l, r, x, y, k = map(int, raw_input().split())

for i in xrange(x, y+1):
    if l <= i * k <= r:
        print 'YES'
        quit()

print 'NO'