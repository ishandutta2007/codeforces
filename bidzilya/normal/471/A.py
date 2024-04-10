x = map(int, raw_input().split(' '))

is_bear = False
for i in xrange(6):
    for j in xrange(i + 1, 6):
        if x[i] != x[j]:
            good = True
            val = -1
            for k in xrange(6):
                if k != i and k != j:
                    if val == -1:
                        val = x[k]
                    elif val != x[k]:
                        good = False
            if good:
                is_bear = True

is_elephant = False
for i in xrange(6):
    for j in xrange(i + 1, 6):
        if x[i] == x[j]:
            good = True
            val = -1
            for k in xrange(6):
                if k != i and k != j:
                    if val == -1:
                        val = x[k]
                    elif val != x[k]:
                        good = False
            if good:
                is_elephant = True

if is_bear:
    print 'Bear'
elif is_elephant:
    print 'Elephant'
else:
    print 'Alien'