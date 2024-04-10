n = int(input())
a = (n & 32) >> 5
b = (n & 16) >> 4
c = (n & 8) >> 3
d = (n & 4) >> 2
e = (n & 2) >> 1
f = n & 1

print(32 * a + 16 * f + 8 * d + 4 * c + 2 * e + b)