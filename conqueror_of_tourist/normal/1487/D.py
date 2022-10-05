t = int(input())
for _ in range(t):
    n = int(input())
    lo = 0
    hi = 10 ** 6
    
    while hi - lo > 1:
        x = (lo + hi) // 2
        a = 2 * x + 1
        c = (a * a + 1)//2
        if c <= n:
            lo = x
        else:
            hi = x
    print(lo)