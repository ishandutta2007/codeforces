t = int(input())
for _ in range(t):
    p, q = map(int, input().split())
    out = []
    nq = q
    for test in range(2, 10**5):
        if q % test == 0:
            p2 = p
            while p2 % q == 0:
                p2 //= test
            out.append(p2)
        while nq % test == 0:
            nq //= test
    if nq > 1:
        while p % q == 0:
            p //= nq
        out.append(p)
    
    print(max(out))