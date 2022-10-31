a = [1, 2]
for i in xrange(input()):
    v = input()
    if v not in a:
        print 'NO'
        quit()
    a = [v, 6 - sum(a)]

print 'YES'