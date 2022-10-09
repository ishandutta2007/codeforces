for testcase in range(int(input())):
    a, b, n = map(int, input().split())
    cnt = 1
    while a % 2 == 0:
        a //= 2
        cnt *= 2
    while b % 2 == 0:
        b //= 2
        cnt *= 2
    print("YES" if cnt >= n else "NO")