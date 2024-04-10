t = int(input())
for _ in range(t):
    n = int(input())
    if n % 7 == 0:
        print(n)
        continue

    n -= n % 10
    while n % 7:
        n += 1
    print(n)