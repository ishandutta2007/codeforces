import sys
input = sys.stdin.readline

def gcd(x, y):
    if x < y:
        x, y = y, x
    while y:
        x, y = y, x % y
    return x

t = int(input())
for _ in range(t):
    a, b, q = map(int, input().split())
    lcm = a * b // gcd(a,b)
    g = gcd(a,b)
    m = max(a,b)

    def f(x):
        total = x // lcm
        extra = x % lcm
        return x - (m * total + min(m,extra))
        
    
    out = [0] * q
    for i in range(q):
        l, r = map(int, input().split())
        out[i] = f(r + 1) - f(l)
        
    print(*out, sep = ' ')