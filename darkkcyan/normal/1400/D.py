for test in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    
    cnt = [0] * (n + 10)
    ans = 0
    for l in range(n):
        cur = 0
        for r in range(l + 1, n):
            if a[l] == a[r]:
                ans += cur
            cur += cnt[a[r]]
        cnt[a[l]] += 1
    print(ans)