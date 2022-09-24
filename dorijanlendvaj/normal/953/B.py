def gcd(a, b):
    if b == 0:
        return a
    return gcd(b,a%b)

n = raw_input()
ar = map(int, raw_input().split())
ar.sort()
re = ar[1]-ar[0]
mi = ar[0]
ma = ar[0]
i = 0
for x in ar:
    if x < mi:
        mi = x
    if x > ma:
        ma = x
    if i < int(n)-1:
        re = gcd (re, ar[i+1]-ar[i])
    i = i + 1

print abs((ma-mi)/re)-int(n)+1