for testcase in range(int(input())):
    n, k = map(int, input().split())
    cur = 1
    ans = 0
    while cur < k and cur < n:
        cur *= 2
        ans += 1
    ans += (n - cur + k - 1) // k
    print(ans)