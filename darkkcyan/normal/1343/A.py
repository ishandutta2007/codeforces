for _ in range(int(input())):
    n = int(input())
    p = 1
    while p <= n:
        p = p * 2 + 1
        if n % p == 0:
            print(n // p)
            break