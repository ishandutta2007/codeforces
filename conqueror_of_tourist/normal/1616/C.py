import sys
input = sys.stdin.readline

from math import gcd

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    poss = [n - 1]

    for i in range(n):
        for j in range(i + 1, n):
            d = a[j] - a[i]
            di = j - i
            g = gcd(d, di)

            d //= g
            di //= g

            ct = 0
            for k in range(n):
                if (k - i) % di == 0 and a[k] == a[i] + d * ((k - i) // di):  
                    ct += 1
            assert ct >= 2
            poss.append(n - ct)
    out.append(min(poss))
print('\n'.join(map(str,out)))