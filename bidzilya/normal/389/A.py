def get_ints():
    return map(int, raw_input().strip().split(' '))

def gcd(a, b):
    while a > 0 and b > 0:
        if a >= b:
            a %= b
        else:
            b %= a
    return a + b


n = int(raw_input())
a = get_ints()
r = a[0]
for i in xrange(1, n):
    r = gcd(r, a[i])
print r * n