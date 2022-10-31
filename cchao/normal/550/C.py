s = raw_input()
for x in xrange(0, 1000, 8):
    t = str(x)
    j = 0
    for c in s:
        if c == t[j]:
            j += 1
            if j == len(t):
                print 'YES'
                print x
                quit()
print 'NO'