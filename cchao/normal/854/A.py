from fractions import gcd

n = input()

for i in xrange(n/2, 0, -1):
    j = n - i
    if gcd(i, j) == 1:
        print i, j
        quit()