n, m = map(int, raw_input().split(' '))
for i in xrange(n):
    if i % 2 == 0:
        print '#' * m
    else:
        if (i / 2) % 2 == 0:
            print ('.' * (m - 1)) + '#'
        else:
            print '#' + ('.' * (m - 1))