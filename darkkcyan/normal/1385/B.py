for testcase in range(int(input())):
    n = int(input())
    has = [False] * (n + 1)
    for i in map(int, input().split()):
        if has[i]:
            continue
        print(i, end=' ')
        has[i] = True
    print()