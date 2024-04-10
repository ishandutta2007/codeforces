from __future__ import print_function, division
import sys

n, t = map(int, raw_input().split())
a = raw_input()
b = raw_input()

dif = sum([int(a[i] != b[i]) for i in xrange(0, n)])

usedif = 0
usesame = 0
if dif <= t:
    usedif = dif
    usesame = n - t
else:
    usedif = 2 * t - dif
    usesame = n - dif

#print(usedif, usesame)

if usedif < 0 or usesame < 0:
    print(-1)
    sys.exit(0)

def getdif(s):
    for i in xrange(ord('a'), ord('z') + 1):
        ch = chr(i)
        if not ch in s:
            return ch

prev = False
ans = []
for i in xrange(0, n):
    ch = ' '
    if a[i] == b[i]:
        if usesame > 0:
            ch = a[i]
            usesame -= 1
        else:
            ch = getdif(a[i])
    else:
        if usedif > 0:
            ch = getdif(a[i] + b[i])
            usedif -= 1
        else:
            if prev:
                ch = a[i]
            else:
                ch = b[i]
            prev = not prev
    ans.append(ch)

print(''.join(ans))