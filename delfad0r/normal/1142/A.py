import math

n, k = map(int, input().split())
a, b = map(int, input().split())

s = [1 if l == 0 else n * k // math.gcd(n * k, l) for i in range(n) for l in (abs(k * i - b - a), abs(k * i + b - a))]
print(min(s), max(s))