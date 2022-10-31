n, k = map(int, raw_input().split())

def cnt(x, b):
    r = 0
    while x % b == 0:
        x /= b
        r += 1
    return r

a = cnt(n, 2)
b = cnt(n, 5)

while a < k:
    n *= 2
    a += 1

while b < k:
    n *= 5
    b += 1

print n