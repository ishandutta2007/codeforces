def get_ints():
    return map(int, raw_input().strip().split(' '))

n = int(raw_input())

if n % 2 == 0:
    for i in xrange(0, n, 2):
        print i + 2, i + 1,
else:
    print -1