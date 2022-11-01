import sys
import math
import random

def gcd(x, y):
    if (x == 0):
        return y
    else:
        return gcd(y % x, x)


n = int(sys.stdin.readline())

factors = [n]

iter = 0

while iter<20:

    x = random.randint(1,n-1)
    y = (x*x)%n
    sys.stdout.write('sqrt '+str(y)+'\n')
    sys.stdout.flush()
    z = int(sys.stdin.readline())
    if z==-1:
        continue
    new_factors = []
    d=x+z
    for f in factors:
        g = math.gcd(f,d)
        if 1<g and g<f:
            new_factors.append(g)
            new_factors.append(f//g)
        else:
            new_factors.append(f)

    iter+=1
    factors = new_factors

sys.stdout.write('! '+str(len(factors))+' ')
for f in factors:
    sys.stdout.write(str(f)+' ')

sys.stdout.flush()