for _ in range(int(input())):
    l, r = map(int, input().split())
    arr = [1, 10, 100, 1000, 1000_0, 1000_00, 1000_000, 1000_000_0, 1000_000_00, 1000_000_000]
    ans = 0
    for i in arr:
        ans += (r//i - l//i)
    print(ans)