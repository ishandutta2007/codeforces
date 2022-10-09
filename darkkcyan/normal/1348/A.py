for testcase in range(int(input())):
    n = int(input())
    ans = 2 ** n + sum(2 ** i for i in range(1, n // 2))
    ans -= sum(2 ** i for i in range(n // 2, n))
    print(abs(ans))