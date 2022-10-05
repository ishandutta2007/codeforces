import sys
input = sys.stdin.readline

n = int(input())
l = []
sumX = 0
sumY = 0
for i in range(n):
    a, b = map(int, input().split())
    
    sumX += a
    sumY += b
    l.append((a,b))

import fractions
avX = fractions.Fraction(sumX, n)
avY = fractions.Fraction(sumY, n)


if int(2 * avX) == 2 * avX and int(2 * avY) == 2 * avY:
    avX = int(2 * avX)
    avY = int(2 * avY)
    
    seen = set()
    for a, b in l:
        ap = 2 * a - avX
        bp = 2 * b - avY

        if ap < 0:
            ap *= -1
            bp *= -1
        elif ap == 0:
            bp = abs(bp)

        seen.add((ap, bp))

    if n == 2 * len(seen):
        print('yes')
    else:
        print('no')
else:
    print('nO')