t = int(input())
for _ in range(t):
    n = int(input())
    p2 = 0
    p3 = 0
    while n % 3 == 0:
        n //= 3
        p3 += 1
    while n % 2 == 0:
        n //= 2
        p2 += 1
    if n == 1:
        diff = p3 - p2
        if diff < 0:
            print(-1)
        else:
            print(p3 + diff)
    else:
        print(-1)