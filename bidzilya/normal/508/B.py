from __future__ import print_function

def get_ints():
    return map(int, raw_input().strip().split(' '))

s = raw_input()
a = [s[i] for i in xrange(len(s))]

r = ord(a[-1]) - ord('0')

n = len(s)

last = -1
alr_swap = False
for i in xrange(n - 1):
    c = ord(a[i]) - ord('0')
    if c % 2 == 0:
        last = i
        if c < r:
            alr_swap = True
            a[i], a[-1] = a[-1], a[i]
            break

if last == -1:
    print(-1)
else:
    if not alr_swap:
        a[last], a[-1] = a[-1], a[last]
    for i in xrange(n):
        print(a[i], end='')