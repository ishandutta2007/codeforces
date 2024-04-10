for testcase in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    x = list(set(a))
    if len(x) > k:
        print(-1)
        continue

    x.extend(range(1, 1 + k - len(x)))

    print(k * n)
    print(*(x * n))