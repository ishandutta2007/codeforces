n, m, k = map(int, raw_input().split())

if k == -1 and n % 2 != m % 2:
    print 0
    quit()

mod = 1000000007

def p(x):
    a = 2
    r = 1
    while x:
        if x & 1:
            r = r * a % mod
        a = a * a % mod
        x >>= 1
    return r

print p((n - 1) * (m - 1))