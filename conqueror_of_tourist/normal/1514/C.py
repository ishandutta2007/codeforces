from math import gcd

out = []
prod = 1
n = int(input())
for i in range(n):
    if gcd(i,n) == 1:
        out.append(i)
        prod *= i
        prod %= n

if prod != 1:
    out = [v for v in out if v != prod]

print(len(out))
print(' '.join(map(str,out)))