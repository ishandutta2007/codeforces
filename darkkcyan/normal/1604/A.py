for testcase in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = max(max(0, x - i) for i, x in enumerate(a, 1))
    print(ans)